#ifndef MAT2_H_
#define MAT2_H_

#include "Vec2.h"
class Mat2
{
public://ctor
	Mat2() : topleft(1), topright(0), bottomleft(0), bottomright(1){}
	Mat2(Vec2 vec1, Vec2 vec2) : topleft(vec1.xx), topright(vec2.xx), bottomleft(vec1.yy), bottomright(vec2.yy) {}
	Mat2(float t_left, float t_right, float b_left, float b_right) : topleft(t_left), topright(t_right), bottomleft(b_left), bottomright(b_right) {}

public://public methods
	float Mat2::getTopLeft()
	{
		return topleft;
	}

	Mat2 Mat2::Rotate(float degrees)
	{
		return Mat2(cosf(degrees), -sinf(degrees), sinf(degrees), cosf(degrees));
	}

	Mat2 Mat2::Scale(float scale)
	{
		return Mat2(scale, 0, 0, scale);
	}

	Mat2 Mat2::Scale(float scaleX, float scaleY)
	{
		return Mat2(scaleX, 0, 0, scaleY);
	}

	Mat2 Mat2::operator*(Mat2 mat)
	{
		return Mat2(topleft * mat.topleft + topright * mat.bottomleft, topleft * mat.topright + topright * mat.bottomright,
			bottomleft * mat.topleft + bottomright * mat.topright, bottomleft * mat.topright + bottomright * mat.bottomright);
	}

	Vec2 Mat2::operator*(Vec2 vec)
	{
		return Vec2(topleft * vec.xx + topright * vec.yy,
			bottomleft * vec.xx + bottomright * vec.yy);
	}
public: //vairable
	float topleft;
	float topright;
	float bottomleft;
	float bottomright;

};

#endif // ndef MAT2_H_
