#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2
{
public:
	float x, y; //The x and y components of the vector

	//Initializing Ctor
	Vector2(float X, float Y) :
			x(X), y(Y)
	{
	}
	//Copy Ctor
	Vector2(Vector2* vec) :
			x(vec->x), y(vec->y)
	{
	}

	//Vector addition
	Vector2 operator+(Vector2 vec)
	{
		return new Vector2(x + vec.x, y + vec.y);
	}
	//Vector subtraction
	Vector2 operator-(Vector2 vec)
	{
		return new Vector2(x - vec.x, y - vec.y);
	}
	//Vector multiplication
	Vector2 operator*(float scale)
	{
		return new Vector2(x * scale, y * scale);
	}
	//Vector division
	Vector2 operator/(float scale)
	{
		return new Vector2(x / scale, y / scale);
	}

	//Dot product
	float Dot(Vector2 vec)
	{
		return (x * vec.x + y * vec.y);
	}
	//Convenience method--Calculates squared length, avoiding costly square root operation
	float LengthSq()
	{
		return (pow(x, 2) + pow(y, 2));
	}
	//Calculates the length
	float Length()
	{
		return sqrt(LengthSq());
	}
	//Normalizes the vector
	Vector2 Normalize()
	{
		return ((*this) / Length());
	}
	//Convenience method -- Calculates the squared distance, avoiding costly square root method
	float DistanceSq(Vector2 vec)
	{
		return (pow(vec.x - x, 2) + pow(vec.y - y, 2));
	}
	//Calculates the distance from another vector to this one
	float Distance(Vector2 vec)
	{
		return (sqrt(DistanceSq(vec)));
	}
};

#endif

