#include "Cowboy.hpp"
#include "Point.hpp"
#include <string>
#include <ostream>

namespace ariel
{
    Cowboy::Cowboy(const string &cowboy_name, Point location) : Character(location, 110, cowboy_name), bullets_num(6) {}
    void Cowboy::shoot(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("fighter can't shoot himself!");
        }
        if (!this->isAlive() || !enemy->isAlive())
        {
            throw std::runtime_error("fighter is dead!");
        }
        if (this->isAlive() && this->hasboolets())
        {
            enemy->hit(10);
            this->bullets_num = bullets_num-1;
        }
        else if (!this->hasboolets())
        {
            reload();
        }
    }
    bool Cowboy::hasboolets()
    {
        if (this->getBulletsnum() > 0)
        {
            return true;
        }
        return false;
    }
    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw std::runtime_error("fighter is dead!");
        }
        this->bullets_num = 6;
    }
    void Cowboy::attack(Character *enemy)
    {
        shoot(enemy);
    }
    int Cowboy::getBulletsnum()
    {
        return this->bullets_num;
    }

    string Cowboy::print() 
    {
        if (this->isAlive())
        {
            return "C\n name of the character: " + this->character_name + ", hit points: " + std::to_string(this->hit_points) + ", location: " + this->location.print();
        }
        return "C\n name of the character: (" + this->character_name + ")," + " location:" + this->location.print();
    }
}