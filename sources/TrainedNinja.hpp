#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include <string>

using namespace std;

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const string &tranin_name, const Point &location);
    };
}
