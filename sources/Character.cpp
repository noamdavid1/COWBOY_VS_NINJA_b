#include "Character.hpp"
#include "Point.hpp"
#include <cmath>
#include <iostream>

namespace ariel
{
    Character::Character(const Point &location, int hit_points, const string &character_name)
    {
        this->location = location;
        this->hit_points = hit_points;
        this->character_name = character_name;
    }

    Character::~Character() {}

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this != &other)
        {
            this->character_name = move(other.character_name);
            this->location = move(other.location);
            this->hit_points = other.hit_points;
        }
        return *this;
    }

    Character::Character(const Character &other) 
    {
        this->location = other.location;
        this->hit_points = other.hit_points;
        this->character_name = other.character_name;
    }
    
    Character &Character::operator=(const Character &other)
    {
        if (this != &other)
        {
            this->character_name = other.character_name;
            this->location = other.location;
            this->hit_points = other.hit_points;
        }
        return *this;
    }

    bool Character::isAlive() 
    {
        if (this->getHitpoints() > 0)
        {
            return true;
        }
        return false;
    }
    double Character::distance(const Character *other)
    {
        return this->location.distance(other->location);
    }
    void Character::hit(int hitpoints)
    {
        if (hitpoints < 0)
        {
            throw std::invalid_argument("hitpoints cant be negative value!");
        }
        else
        {
            this->hit_points = this->hit_points - hitpoints;
        }
    }
    void Character::attack(Character *enemy)
    { 
    }
    string Character::getName()
    {
        return this->character_name;
    }
    Point Character::getLocation()
    {
        return this->location;
    }
    string Character::print() 
    {
        if (isAlive())
        {
            return "name of the character:" + this->character_name + ", hit points: " + std::to_string(this->hit_points) + ", location: " + this->location.print();
        }
        return "name of the character: (" + this->character_name + "), location:" + this->location.print();
    }

    int Character::getHitpoints()
    {
        return (int)(this->hit_points);
    }

    bool Character::getInAteam()
    {
        return this->inAteam;
    }
    void Character::setInAteam(bool associated)
    {
        this->inAteam = associated;
    }
}