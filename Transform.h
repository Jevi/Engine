#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2.h"

class Transform
{
public:
	Vector2 position;		//Positional vector
	float rotation;			//Rotation in degrees
	float scale;			//the scale is proportionate--same for both width and height

	//Initializing Ctors
	Transform(float PosX, float PosY, float Rot, float Scale) :
			position(PosX, PosY), rotation(Rot), scale(Scale)
	{
	}

	Transform(Vector2* Pos, float Rot, float Scale) :
			position(Pos), rotation(Rot), scale(Scale)
	{
	}

	//Translates by Vec
	void Translate(Vector2 Vec)
	{
		position = position + Vec;
	}

	//Translates by X and Y
	void Translate(float X, float Y)
	{
		position.x += X;
		position.y += Y;
	}

	//Rotates by Theta, staying withing the (0, 360] boundary.
	void Rotate(float Theta)
	{
		rotation += Theta;
		if (rotation >= 360)
		{
			rotation -= 360;
		}
		if (rotation < 0)
		{
			rotation += 360;
		}
	}
};
#endif
