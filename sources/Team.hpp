#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"

#include <iostream>
#include <vector>

namespace ariel
{

    class Team
    {
    private:
    std::vector<Character*> fighters;
    std::vector<Cowboy*> cowboy_list;
    std::vector<Ninja*> ninja_list;
    Character *leader;
    public:
        Team(Character *leader); //initialization constructor.
        ~Team(); //destruction function.
        vector<Character *> sort(vector<Character *> list);
        void add(Character *player); //add a character to the team.
        virtual void attack(Team *other); //Gets a pointer to the enemy team and attacks it.
        int stillAlive() ; //Returns an integer number of surviving group members.
        void newleader(); //Updates a new leader in case the leader dies.
        Character *getcloser(Team *team,  Character *character); //Returns the fighter closest to the leader of the selected group.
        Character *getcloserteam(Team *team, Character *character);
        vector<Character*> getFighters(); //returns the team structre.
        Character getLeader(); //reaturns the leader of the team.
        virtual void print(); //Goes through all the characters in the group and prints their details.
    };

}