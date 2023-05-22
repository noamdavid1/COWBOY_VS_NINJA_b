#pragma once
#include "Point.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    class Character
    {
    protected:
        Point location;
        int hit_points;
        string character_name;
        bool inAteam = false;

    public:
        Character(const Point &location, int hit_points, const string &character_name); // initialization constructor.
        Character &operator=(Character&& other) noexcept;
        virtual ~Character() ; // destruction function.
        Character(const Character &other);
        Character &operator=(const Character &other);
        
        bool isAlive() ;                    // returns true if the character still in the game.
        double distance(const Character *other); // returns the distance between two character.
        void hit(int hitpoints);                 // Subtracts the appropriate amount of hit points from the character.
        virtual void attack(Character *enemy);
        string getName();             // returns the name of the character.
        Point getLocation();          // returns the location of the character.
        virtual string print() ; // Prints the name of the character, the number of its hit points, and the point where the character is.
        int getHitpoints(); // returns the hit points of the character.
        bool getInAteam();
        void setInAteam(bool associated);
        friend bool operator==(const Character &character1, const Character &character2)
        {
            return &character1 == &character2;
        }
    };
}