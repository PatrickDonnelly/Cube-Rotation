#include "Matrix3.h"
#define PI 3.14159265358979323846

Matrix3::Matrix3() :
	m11{ 0.0f },
	m12{ 0.0f },
	m13{ 0.0f },
	m21{ 0.0f },
	m22{ 0.0f },
	m23{ 0.0f },
	m31{ 0.0f },
	m32{ 0.0f },
	m33{ 0.0f }
{
}

Matrix3::Matrix3(float t_a11, float t_a12, float t_a13, 
				float t_a21, float t_a22, float t_a23, 
				float t_a31, float t_a32, float t_a33) :
	m11{ t_a11 },
	m12{ t_a12 },
	m13{ t_a13 },
	m21{ t_a21 },
	m22{ t_a22 },
	m23{ t_a23 },
	m31{ t_a31 },
	m32{ t_a32 },
	m33{ t_a33 }
{
}

Matrix3::Matrix3(Vector3 row1, Vector3 row2, Vector3 row3) :
	m11{ row1.getX() },
	m12{ row1.getY() },
	m13{ row1.getZ() },
	m21{ row2.getX() },
	m22{ row2.getY() },
	m23{ row2.getZ() },
	m31{ row3.getX() },
	m32{ row3.getY() },
	m33{ row3.getZ() }
{
}


Matrix3::~Matrix3()
{
}

std::string Matrix3::toString() const
{
	const std::string output = "[" + std::to_string(m11) + "," + std::to_string(m12) + "," + std::to_string(m13) + "]\n"
		+ "[" + std::to_string(m21) + "," + std::to_string(m22) + "," + std::to_string(m23) + "]\n"
		+ "[" + std::to_string(m31) + "," + std::to_string(m32) + "," + std::to_string(m33) + "]";
	return output;

}

Matrix3 Matrix3::operator+(Matrix3 M2)
{
	return Matrix3{ m11 + M2.m11, m12 + M2.m12, m13 + M2.m13,
					m21 + M2.m21, m22 + M2.m22, m23 + M2.m23,
					m31 + M2.m31, m32 + M2.m32, m33 + M2.m33 };
}

Matrix3 Matrix3::operator-(Matrix3 M2)
{
	return Matrix3{	m11 - M2.m11, m12 - M2.m12, m13 - M2.m13,
					m21 - M2.m21, m22 - M2.m22, m23 - M2.m23,
					m31 - M2.m31, m32 - M2.m32, m33 - M2.m33 };
}

Matrix3 Matrix3::operator*(Matrix3 M2)
{
	Matrix3 answer{};
	answer.m11 = row(0) * M2.column(0);
	answer.m12 = row(0) * M2.column(1);
	answer.m13 = row(0) * M2.column(2);

	answer.m21 = row(1) * M2.column(0);
	answer.m22 = row(1) * M2.column(1);
	answer.m23 = row(1) * M2.column(2);

	answer.m31 = row(2) * M2.column(0);
	answer.m32 = row(2) * M2.column(1);
	answer.m33 = row(2) * M2.column(2);

	return answer;
}

Vector3 Matrix3::operator*(Vector3 V2)
{
	return  Vector3(m11 * V2.getX() + m12 * V2.getY() + m13 * V2.getZ(),
					m21 * V2.getX() + m22 * V2.getY() + m23 * V2.getZ(),
					m31 * V2.getX() + m32 * V2.getY() + m33 * V2.getZ());
}

Matrix3 Matrix3::operator*(float x)
{
	Matrix3 answer = Matrix3();
	answer.m11 = m11 * x;
	answer.m12 = m12 * x;
	answer.m13 = m13 * x;

	answer.m21 = m21 * x;
	answer.m22 = m22 * x;
	answer.m23 = m23 * x;

	answer.m31 = m31 * x;
	answer.m32 = m32 * x;
	answer.m33 = m33 * x; ;

	return answer;
}

Matrix3 Matrix3::transpose(Matrix3 M1)
{
	return Matrix3{ M1.m11, M1.m21, M1.m31,
					M1.m12, M1.m22, M1.m32,
					M1.m13, M1.m23, M1.m33 };
}

float Matrix3::determinant(Matrix3 M1) 
{
	return {	M1.m11 * M1.m22 * M1.m33 - 
				M1.m11 * M1.m32 * M1.m23 + 
				M1.m21 * M1.m32 * M1.m13 - 
				M1.m31 * M1.m22 * M1.m13 + 
				M1.m31 * M1.m12 * M1.m23 - 
				M1.m21 * M1.m12 * M1.m33 };
}

Matrix3 Matrix3::inverse(Matrix3 M1)
{
	float det = determinant(M1);
	if (det == 0)
		return Matrix3();
	else
	{
		float scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.m11 = scale * (M1.m22 * M1.m33 - M1.m23 * M1.m32);
		answer.m12 = scale * (M1.m13 * M1.m32 - M1.m12 * M1.m33);
		answer.m13 = scale * (M1.m12 * M1.m23 - M1.m13 * M1.m22);

		answer.m21 = scale * (M1.m23 * M1.m31 - M1.m21 * M1.m33);
		answer.m22 = scale * (M1.m11 * M1.m33 - M1.m13 * M1.m31);
		answer.m23 = scale * (M1.m13 * M1.m21 - M1.m11 * M1.m23);

		answer.m31 = scale * (M1.m21 * M1.m32 - M1.m22 * M1.m31);
		answer.m32 = scale * (M1.m12 * M1.m31 - M1.m11 * M1.m32);
		answer.m33 = scale * (M1.m11 * M1.m22 - M1.m12 * M1.m21);

		return answer;
	}
}

Vector3 Matrix3::row(int i)
{
	switch (i)
	{
	case 0:
		return Vector3{ m11, m12, m13 };
	case 1:
		return Vector3{ m21, m22, m23 };
	case 2:
	default:
		return  { m31, m32, m33 };
	}
}

Vector3 Matrix3::column( int i) 
{
	switch (i)
	{
	case 0:
		return Vector3{ m11, m21, m31 };
	case 1:
		return Vector3{ m12, m22, m32 };
	case 2:
	default:
		return Vector3{ m13, m23, m33 };
	}
}

Matrix3 Matrix3::rotationZ(float t_angle)
{
	float radians = PI / 180 * t_angle;
	Matrix3 answer = Matrix3();
	return Matrix3{
		std::cos(radians), -std::sin(radians), 0.0,
		std::sin(radians), std::cos(radians), 0.0,
		0.0, 0.0, 1.0 };
}

Matrix3 Matrix3::rotationY(float t_angle)
{
	float radians = PI / 180 * t_angle;
	Matrix3 answer = Matrix3();
	return Matrix3{
		std::cos(radians), 0.0, std::sin(radians),
		0.0 ,1.0 ,0.0,
		-std::sin(radians), 0.0, std::cos(radians)
	};
}

Matrix3 Matrix3::rotationX(float t_angle)
{
	float radians = PI / 180 * t_angle;
	Matrix3 answer = Matrix3();
	return Matrix3{
		1.0 , 0.0 , 0.0,
		0.0 ,std::cos(radians) ,-std::sin(radians),
		0.0 , std::sin(radians), std::cos(radians) };
}

Matrix3 Matrix3::Rotation(int t_angle)
{
	float radians = PI / 180 * t_angle;
	Matrix3 answer = Matrix3();
	answer.m11 = cos(radians);
	answer.m12 = sin(radians);
	answer.m13 = 0;
	answer.m21 = -sin(radians);
	answer.m22 = cos(radians);
	answer.m23 = 0;
	answer.m31 = 0;
	answer.m32 = 0;
	answer.m33 = 1;

	return answer;
}

Matrix3 Matrix3::translation(float dx, float dy)
{
	Matrix3 answer = Matrix3();
	answer.m11 = 1;
	answer.m12 = 0;
	answer.m13 = 0;
	answer.m21 = 0;
	answer.m22 = 1;
	answer.m23 = 0;
	answer.m31 = dx;
	answer.m32 = dy;
	answer.m33 = 1;

	return answer;
}

Matrix3 Matrix3::scale(float dx, float dy)
{
	Matrix3 answer = Matrix3();
	answer.m11 = (float)dx / 100;
	answer.m12 = 0;
	answer.m13 = 0;
	answer.m21 = 0;
	answer.m22 = (float)dy / 100;
	answer.m23 = 0;
	answer.m31 = 0;
	answer.m32 = 0;
	answer.m33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale3D(float dx)
{
	Matrix3 answer = Matrix3();
	answer.m11 = (float)dx / 100;
	answer.m12 = 0;
	answer.m13 = 0;
	answer.m21 = 0;
	answer.m22 = (float)dx / 100;
	answer.m23 = 0;
	answer.m31 = 0;
	answer.m32 = 0;
	answer.m33 = (float)dx / 100;

	return answer;
}

Matrix3 Matrix3::operator-()
{

	Matrix3 answer = Matrix3();
	answer.m11 = m11 * -1;
	answer.m12 = m12 * -1;
	answer.m13 = m13 * -1;
	answer.m21 = m13 * -1;
	answer.m22 = m22 * -1;
	answer.m23 = m23 * -1;
	answer.m31 = m31 * -1;
	answer.m32 = m32 * -1;
	answer.m33 = m33 * -1;

	return answer;
}
