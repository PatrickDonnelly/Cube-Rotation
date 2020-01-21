#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	float m11;
	float m12; 
	float m13;
	float m21; 	
	float m22; 
	float m23;
	float m31; 
	float m32; 
	float m33;

	Matrix3();
	Matrix3(
		float t_a11, float t_a12, float t_a13,
		float t_a21, float t_a22, float t_a23,
		float t_a31, float t_a32, float t_a33);

	Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);

	~Matrix3();

	std::string toString()const;

	Matrix3 operator +(Matrix3 M2);
	Matrix3 operator -(Matrix3 M2);
	Matrix3 operator *(Matrix3 M2);
	Vector3 operator *(Vector3 V2);
	Matrix3 operator *(float x);

	Matrix3 transpose(Matrix3 M1);
	float determinant(Matrix3 M1);
	Matrix3 inverse(Matrix3 M1);

	Vector3 row( int i);
	Vector3 column( int i) ;


	static Matrix3 rotationZ(float t_angle);
	static Matrix3 rotationY(float t_angle);
	static Matrix3 rotationX(float t_angle);

	Matrix3 Rotation(int t_angle);

	Matrix3 translation(float dx, float dy); // 2d translation make sure z=1
	Matrix3 scale(float dx, float dy);
	Matrix3 Scale3D(float dx);

	Matrix3 operator-();
};

