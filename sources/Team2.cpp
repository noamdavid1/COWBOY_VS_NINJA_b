#include "Team2.hpp"
#include "Team.hpp"

namespace ariel
{

    Team2::Team2(Character *leader) : Team(leader) {}
    void Team2::attack(Team *other)
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
        if (!getLeader().isAlive())
        {
            return;
        }
        Character *victim = nullptr;
        victim = helpfunc(other);

        for (Character *fighter : this->getFighters())
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
            if (!other->getLeader().isAlive())
            {
                break;
            }
            victim = helpfunc(other);
            if (victim == nullptr || !victim->isAlive())
            {
                continue;
            }
            fighter->attack(victim);
        }
        other->newleader();
    }

    Character *Team2::helpfunc(Team *other)
    {
        Character *close = nullptr;
        double mostclose = std::numeric_limits<double>::max();
        for (Character *fighter : other->getFighters())
        {
            if (!fighter->isAlive() || getLeader().distance(fighter) < 0)
            {
                continue;
            }
            if (getLeader().distance(fighter) < mostclose)
            {
                mostclose = getLeader().distance(fighter);
                close = fighter;
            }
        }
        return close;
    }

    void Team2::print()
    {
        for (Character *fighter : getFighters())
        {
            cout << fighter->print() << "\n"
                 << endl;
        }
    }
}