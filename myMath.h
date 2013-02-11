#ifndef MY_MATH_H
#define MY_MATH_H

class myMath {
public:

	static float DegreesToRadians(float degrees) {
		return (degrees * 3.1415926f) / 180.0f;
	}

	static float RadiansToDegrees(float radians) {
		return radians * 180.0f / 3.1415926f;
	}

	static float PixelsToMeters(float pixels) {
		return pixels / 30.0f;
	}

	static float MetersToPixels(float meters) {
		return meters * 30.0f;
	}

};

#endif
