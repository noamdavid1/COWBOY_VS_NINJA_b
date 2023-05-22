#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include <string>

using namespace std;

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &oldnin_name,const Point &location);
    };
}