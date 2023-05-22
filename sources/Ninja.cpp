#include "Ninja.hpp"
#include <ostream>

namespace ariel
{
    Ninja::Ninja(const string &ninj_name, int hit_points, const Point &location, int speed) : Character(location, hit_points, ninj_name), speed(speed) {}

    void Ninja::move(Character *enemy)
    {
        if(this==enemy){
            throw std::runtime_error("fighter can't slash himself!");
        }
        if (!enemy->isAlive() || !this->isAlive())
        {
            throw std::runtime_error("can't move dead fighter!");
        }
        this->location = Point::moveTowards(this->location, enemy->getLocation(), this->getSpeed());
    }

    void Ninja::slash(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("fighter can't slash himself!");
        }
        if (!this->isAlive() || !enemy->isAlive())
        {
            throw std::runtime_error("fighter is dead!");
        }
        if (this->isAlive() && (this->distance(enemy) < 1))
        {
            enemy->hit(40);
        }
    }

    void Ninja::attack(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("fighter can't slash himself!");
        }
        if (!this->isAlive() || !enemy->isAlive())
        {
            throw std::runtime_error("fighter is dead!");
        }
        if (this->isAlive() && this->distance(enemy) < 1)
        {
            slash(enemy);
        }else if (this->distance(enemy) >= 1){
            move(enemy);
        }
    }

    int Ninja::getSpeed()
    {
        return this->speed;
    }
    string Ninja::print() 
    {
        if (isAlive())
        {
            return "N\n name of the character: " + this->character_name + ", hit points: " + std::to_string(this->hit_points) + ", location: " + this->location.print();
        }
        return "N\n name of the character: (" + this->character_name + ")," + " location:" + this->location.print();
    }

}
