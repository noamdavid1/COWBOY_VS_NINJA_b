#pragma once

#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(); //defult constructor.
        Point(double x, double y); //initializtion constructor.
        double distance(Point point); //returns the distance between two points.
        string print() const; //Prints the two coordinates in parentheses.
        //friend Point moveTowards(Point src, Point des, double dis);
        static Point moveTowards(Point point, Point other, double distance); //Gets a source point, destination point and distance. The function returns the closest point to the target point.
        bool operator==(const Point &other)const; //Comparison operator between 2 points.
        double getX(); //returns the X value.
        double getY(); //returns the Y value.
    };
}