#include <iostream>
#include "Vector2D.h"
using namespace std;

Vector2D::Vector2D()	
	{
		x = 0.0;
		y = 0.0;
	}
	
Vector2D::Vector2D(double in_x, double in_y)
	{
		x = in_x;
		y = in_y;
	}

	
Vector2D operator*(Vector2D v1, double d)
{
	return Vector2D(v1.x*d,v1.y*d);
}

Vector2D operator/(Vector2D v1, double d)
{
	if(d==0.0)
		return Vector2D(v1.x,v1.y);
	else
		return Vector2D(v1.x/d,v1.y/d);
}

ostream& operator<<(ostream& os, const Vector2D& v)
{
    os << "<" << v.x << ", " << v.y << ">" << endl;
    return os;
}