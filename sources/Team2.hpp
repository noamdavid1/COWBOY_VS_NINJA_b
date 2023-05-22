#pragma once

#include "Team.hpp"


#include <iostream>
#include <vector>

namespace ariel
{

    class Team2 : public Team
    {

    public:
        Team2(Character *leader);
        void attack(Team* other) override;
        void print() override;
        Character *helpfunc(Team *other);

    };

}