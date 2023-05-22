#include "Point.hpp"

#include <iostream>
#include <cmath>

namespace ariel
{
    Point::Point() : x(0), y(0) {}
    Point::Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    bool Point::operator==(const Point &other) const
    {
        return (this->x == other.x && this->y == other.y);
    }
    double Point::distance(Point point)
    {
        double dx = this->x - point.x;
        double dy = this->y - point.y;
        return sqrt(dx * dx + dy * dy);
    }
    string Point::print() const
    {
        string points = "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
        return points;
    }

    Point Point::moveTowards(Point point, Point other, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("distance can't be negative value!");
        }
        double dis= point.distance(other);
        if (dis <= distance)
        {
            return other;
        }
        double ratio = distance / dis;
        double resultx = point.x*( 1 - ratio)+(ratio*other.x);
        double resulty = point.y*(1-ratio)+(ratio*other.y);
        Point result(resultx, resulty);
        return result;
    }

    double Point::getX()
    {
        return this->x;
    }
    double Point::getY()
    {
        return this->y;
    }

}
