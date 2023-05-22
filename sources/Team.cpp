#include "Team.hpp"
#include <ostream>
#include <limits>
#include <cfloat>

namespace ariel
{
    Team::Team(Character *leader)
    {
        this->leader = leader;
        if (leader->getInAteam())
        {
            throw std::runtime_error("this fighter is already part of the team!");
        }
        this->fighters.push_back(leader);
        this->leader->setInAteam(true);
    }

    Team::~Team() {}

    void Team::add(Character *player)
    {
        if (player->getInAteam())
        {
            throw std::runtime_error("this fighter is already part of the team!");
        }

        if (this->fighters.size() >= 10)
        {
            throw std::runtime_error("the team is full!");
        }
        if (this->fighters.size() < 10)
        {
            if (Ninja *n = dynamic_cast<Ninja *>(player))
            {

                ninja_list.push_back(n);
            }
            if (Cowboy *c = dynamic_cast<Cowboy *>(player))
            {
                cowboy_list.push_back(c);
            }
            player->setInAteam(true);
            this->fighters.push_back(player);
        }
    }

    Character *Team::getcloser(Team *team, Character *character)
    {
        double mostcloser = std::numeric_limits<double>::max();
        Character *close = nullptr;
        
        for (Character *fighter : team->fighters)
        {
            if (!fighter->isAlive() || fighter->distance(character) < 0)
            {
                continue;
            }
            if (fighter->distance(character) < mostcloser)
            {
                mostcloser = fighter->distance(character);
                close = fighter;
            }
        }
        return close;
    }

    Character *Team::getcloserteam(Team *team, Character *character){
        double mostcloser = std::numeric_limits<double>::max();
        Character *close = nullptr;
        vector<Character *> newTeam = sort(team->fighters);
        for (Character *fighter : newTeam)
        {
            if (!fighter->isAlive() || fighter->distance(character) < 0)
            {
                continue;
            }
            if (fighter->distance(character) < mostcloser)
            {
                mostcloser = fighter->distance(character);
                close = fighter;
            }
        }
        return close;
    }


    void Team::newleader()
    {
        if (this->leader->isAlive())
        {
            return;
        }
        Character *temp = nullptr;
        temp = getcloser(this, this->leader);
        leader = temp;
    }

    vector<Character *> Team::sort(vector<Character *> list) {
    vector<Character *> newList;
    //first - cowboys:
    for (Character* c : list) {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(c)) {
            if (cowboy->isAlive())
                newList.push_back(cowboy);
        }
    }
    //second - ninjas:
    for (Character* c : list) {
        if (Ninja* ninja = dynamic_cast<Ninja*>(c)) {
            if (ninja->isAlive())
                newList.push_back(ninja);
        }
    }
    return newList;
}

    void Team::attack(Team *other)
    {
        if (other == nullptr)
        {
            throw std::invalid_argument("enemy team is null!");
        }
        if (this->stillAlive() == 0 || other->stillAlive() == 0)
        {
            throw std::runtime_error("there is no one alive on the team!");
        }
        newleader();
        if (!this->leader->isAlive())
        {
            return;
        }
        Character *victim = nullptr;
        victim = getcloserteam(other, this->leader);

        for (Character *fighter : this->fighters)
        {
            if (!fighter->isAlive())
            {
                continue;
            }
            if (other->stillAlive() == 0)
            {
                return;
            }
            other->newleader();
            if (!other->leader->isAlive())
            {
                break;
            }
            victim = getcloserteam(other, this->leader);
            if (victim == nullptr || !victim->isAlive())
            {
                continue;
            }
            fighter->attack(victim);
        }
        other->newleader();
    }

    Character Team::getLeader(){
        return *this->leader;
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (Character *fighter : this->fighters)
        {
            if (fighter->isAlive())
            {
                count++;
            }
        }
        return count;
    }
    vector<Character *> Team::getFighters()
    {
        return this->fighters;
    }

    void Team::print()
    {
        for (Character *fighter : cowboy_list)
        {
            cout << fighter->print() << "\n"
                 << endl;
        }
        for (Character *fighter : ninja_list)
        {
            cout << fighter->print() << "\n"
                 << endl;
        }
    }
}