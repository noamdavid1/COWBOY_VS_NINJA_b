#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include <utility>
#include <string>

using namespace std;

namespace ariel
{
    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(const string &younin_name, const Point &location);
    };
}
