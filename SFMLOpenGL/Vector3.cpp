/// <summary>
/// Vector 3 class
/// </summary>
#include "Vector3.h"
#define PI 3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
Vector3::Vector3() :
	x{ 0.0f },
	y{ 0.0f },
	z{ 0.0f }
{
}

/// <summary>
/// constructor from 3 floats
/// </summary>
/// <param name="t_x">x componenet</param>
/// <param name="t_y">y componenet</param>
/// <param name="t_z">z componenet</param>
Vector3::Vector3(float x1, float y1, float z1) :
	x{ x1 },
	y{ y1 },
	z{ z1 }
{
}

Vector3::~Vector3()
{
}

float Vector3::getX()
{
	return x;
}

void Vector3::setX(float t_x)
{
	x = t_x;
}

float Vector3::getY()
{
	return y;
}

void Vector3::setY(float t_y)
{
	y = t_y;
}

float Vector3::getZ()
{
	return z;
}

void Vector3::setZ(float t_z)
{
	z = t_z;
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string Vector3::toString()
{
	const std::string output = "[" + std::to_string(getX()) + "," + std::to_string(getY()) + "," + std::to_string(getZ()) + "]";
	return output;
}



/// <summary>
/// overload for plus (addition opperator)
/// </summary>
/// <param name="t_right">the vector to add to current vector</param>
/// <returns>sum of both vectors</returns>
Vector3 Vector3::operator+(Vector3 V2)
{
	return Vector3{ x + V2.x, y + V2.y, z + V2.z };
}

/// <summary>
/// operator overload for minus (subtract operator)
/// </summary>
/// <param name="t_right">ther vector to subtract from the current</param>
/// <returns>the difference between the vectors</returns>
Vector3 Vector3::operator-(Vector3 V2)
{
	return Vector3{ x - V2.x, y - V2.y, z - V2.z };
}
/// <summary>
/// multiply by a scalar (float) change the vector magnitude by the scaling factor
/// </summary>
/// <param name="t_scalar">value to multiply by</param>
/// <returns>re-sized vector</returns>
Vector3 Vector3::operator*(float k)
{
	return Vector3{ x *k, y *k, z *k };
}

/// <summary>
/// operator overload for uniary negative
/// </summary>
/// <returns>the negative of the vector</returns>
Vector3 Vector3::operator-()
{
	return Vector3{ -x, -y, -z };
}

/// <summary>
/// calculate the lenght of the vector 
/// </summary>
/// <returns>lenght</returns>
float Vector3::length()
{
	float result = std::sqrt(x * x + y * y + z * z);
	return result;
}
/// <summary>
/// the lenght of the vector squared (not square rooted)
/// </summary>
/// <returns>lenght squared</returns>
float Vector3::lengthSquared()
{
	float result = std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);
	return result;
}

/// <summary>
/// Overloaded * operator that returns the scaler product of 2 vectors
/// </summary>
/// <param name="V2"></param>
/// <returns></returns>
float Vector3::operator*(Vector3 V2)
{
	return (x * V2.x + y * V2.y + z * V2.z);
}

/// <summary>
/// multiply by a scalar (int) change the vector magnitude by the scaling factor
/// </summary>
/// <param name="k"></param>
/// <returns></returns>
Vector3 Vector3::operator*(int k)
{
	return  { x * k, y * k, z * k };
}

/// <summary>
/// multiply by a scalar (double) change the vector magnitude by the scaling factor
/// </summary>
/// <param name="k"></param>
/// <returns></returns>
Vector3 Vector3::operator*(double k)
{
	return { x * (float)k, y * (float)k, z * (float)k };
}

/// <summary>
/// Overloaded * operator that returns the vector product of 2 vectors
/// </summary>
/// <param name="V2"></param>
/// <returns></returns>
Vector3 Vector3::operator^(Vector3 V2)
{
	return { y * V2.z - z * V2.y, z * V2.x - x * V2.z, x * V2.y - y * V2.x };
}

/// <summary>
/// re-size current vector to magnitude one
/// </summary>
void Vector3::normalise()
{
	if (length() > 0.0)
	{
		float orignalLenght = length();
		x /= orignalLenght;
		y /= orignalLenght;
		z /= orignalLenght;
	}
}