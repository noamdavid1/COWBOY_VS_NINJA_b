#pragma once


#include "Character.hpp"
#include "Cowboy.hpp"

namespace ariel
{
   class Ninja : public Character
   {

   private:
      int speed;

   public:
      Ninja(const string &ninj_name,int hit_points,const Point &location,int speed); //initialization constructor.
      void move(Character *enemy); //Receives a pointer to the enemy and advances towards the enemy. The ninja advances a distance equal to its speed.
      void slash(Character *enemy); //Receiving a pointer to an enemy, subtracting 40 hit points from the enemy.
      void attack(Character *enemy) override;
      int getSpeed(); //returns the speed of the ninja.
      string print() override; //Prints the ninja's name, how many points he has, and his location.
   };
}