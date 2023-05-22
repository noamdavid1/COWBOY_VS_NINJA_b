#pragma once

#include "Team.hpp"

#include <iostream>
#include <vector>

namespace ariel
{

    class SmartTeam : public Team
    {

    public:
        SmartTeam(Character *leader) : Team(leader) {}
    };

}