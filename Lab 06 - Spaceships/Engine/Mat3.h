#ifndef MAT3_H_
#define MAT3_H_

#include "Vec2.h"
#include "Vec3.h"
#include "Mat2.h"
class Mat3
{
public://ctor
	Mat3::Mat3() : topleft(1), topmiddle(0), topright(0),
				middleleft(0), middlemiddle(1), middleright(0), 
				bottomleft(0), bottommiddle(0), bottomright(1){}
	
	Mat3::Mat3(Vec2 vec1, Vec2 vec2) : topleft(vec1.xx), topmiddle(vec2.xx), topright(0),
									middleleft(vec1.yy), middlemiddle(vec2.yy), middleright(0),
									bottomleft(0), bottommiddle(0), bottomright(1) {}

	Mat3::Mat3(Vec3 vec1, Vec3 vec2, Vec3 vec3) : topleft(vec1.xx), topmiddle(vec2.xx), topright(vec3.xx),
											middleleft(vec1.yy), middlemiddle(vec2.yy), middleright(vec3.yy),
											bottomleft(vec1.zz), bottommiddle(vec2.zz), bottomright(vec3.zz) {}

	Mat3::Mat3(float t_left, float t_middle, float t_right, float m_left, float m_middle, float m_right, float b_left, float b_middle, float b_right) : topleft(t_left), topmiddle(t_middle), topright(t_right),
																																					middleleft(m_left), middlemiddle(m_middle), middleright(m_right),
																																					bottomleft(b_left), bottommiddle(b_middle), bottomright(b_right) {}

public://public methods
	float Mat3::getTopLeft()
	{
		return topleft;
	}

	Mat3 Mat3::Rotate(float degrees)
	{
		return Mat3(cosf(degrees), -sinf(degrees), 0, sinf(degrees), cosf(degrees), 0, 0, 0, 1);
	}

	Mat3 Mat3::Scale(float scale)
	{
		return Mat3(scale, 0, 0, 0, scale, 0, 0, 0, 1);
	}

	Mat3 Mat3::Scale(float scaleX, float scaleY)
	{
		return Mat3(scaleX, 0, 0, 0, scaleY, 0, 0, 0, 1);
	}

	Mat3 Mat3::Translation(float x, float y)
	{
		return Mat3(1, 0, x, 0, 1, y, 0, 0, 1);
	}

	Mat3 Mat3::Translation(Vec2 & t)
	{
		return Mat3(1, 0, t.GetX(), 0, 1, t.GetY(), 0, 0, 1);
	}

	Mat3 Mat3::operator*(Mat3 mat)
	{
		return Mat3(topleft * mat.topleft + topmiddle * mat.middleleft + topright * mat.bottomleft, topleft * mat.topmiddle + topmiddle * mat.middlemiddle + topright *mat.bottommiddle, topleft * mat.topright + topmiddle * mat.middleright + topright * mat.bottomright,
			middleleft * mat.topleft + middlemiddle * mat.middleleft + middleright * mat.bottomleft, middleleft * mat.topmiddle + middlemiddle * mat.middlemiddle + middleright * mat.bottommiddle, middleleft * mat.topright + middlemiddle * mat.middleright + middleright * mat.bottomright,
			bottomleft * mat.topleft + bottommiddle * mat.middleleft + bottomright * mat.bottomleft, bottomleft * mat.topmiddle + bottommiddle * mat.middlemiddle + bottomright * mat.bottommiddle, bottomleft * mat.topright + bottommiddle * mat.middleright + bottomright * mat.bottomright);
	}

	Mat3 Mat3::operator*(Vec2 vec)
	{
		return Mat3(topleft * vec.xx + topmiddle * vec.yy, 0, 0, 0, middleleft * vec.xx + middlemiddle * vec.yy, 0, 0, 0, 1);
	}

	Vec3 Mat3::operator*(Vec3 vec)
	{
		return Vec3(topleft * vec.xx + topmiddle * vec.yy + topright * vec.zz,
			middleleft * vec.xx + middlemiddle * vec.yy + middleright * vec.zz,
			bottomleft * vec.xx + bottommiddle * vec.yy + bottomright * vec.zz);
	}

	Vec3 Mat3::Mult(const Vec3 & v)
	{
		return Vec3(topleft * v.xx + topmiddle * v.yy + topright * v.zz,
			middleleft * v.xx + middlemiddle * v.yy + middleright * v.zz,
			bottomleft * v.xx + bottommiddle * v.yy + bottomright * v.zz);
	}

public: //vairable
	float topleft;
	float topmiddle;
	float topright;
	float middleleft;
	float middlemiddle;
	float middleright;
	float bottomleft;
	float bottommiddle;
	float bottomright;
};

std::ostream& operator<<(std::ostream& os, Mat3 m);
#endif // ndef VEC2_H_