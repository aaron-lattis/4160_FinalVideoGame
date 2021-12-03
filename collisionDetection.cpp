

#include "collisionDetection.h"
#include "Box.h"
#include <cmath>
#include <iostream>


bool collisionDetection(double c1x, double c1y, double c1r, double c2x, double c2y, double c2r)
{

    double xDist;
    double yDist;

    double dist;

    xDist = c1x - c2x;
    yDist = c1y - c2y;

    dist = sqrt(pow(xDist, 2) + pow(yDist, 2));

    if (dist <= c1r + c2r)
    {
        return true;
    }
    else
    {
        return false;
    }

}

