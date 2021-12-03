
#include "Box.h"

Box::Box(int l, int r, int t, int b)
{
    left = l;
    right = r;
    top = t;
    bottom = b;
}
      
Box::Box ()
{

}

Box::~Box()
{
    
}

int Box::l()
{
    return left;
}

int Box::r()
{
    return right;
}

int Box::t()
{
    return top;
}

int Box::b()
{
    return bottom;
}

void Box::l(int l)
{
    left = l;
}

void Box::r(int r)
{
    right = r;
}

void Box::t(int t)
{
    top = t;
}

void Box::b(int b)
{
    bottom = b;
}