#pragma once

#include <iostream>
#include <math.h>
#include <string>


	class Vector3
	{
	private:
		float x;
		float y;
		float z;
	public:
		Vector3();
		~Vector3();

		float getX();
		void setX(float t_x);

		float getY();
		void setY(float t_y);

		float getZ();
		void setZ(float t_z);


		Vector3(float x1, float y1, float z1);

		Vector3 operator +(Vector3 V2);
		Vector3 operator -(Vector3 V2);
		Vector3 operator *(float k);
		// negative of a vector 
		Vector3 operator -();
		float length();
		float lengthSquared();

		float operator *(Vector3 V2);
		Vector3 operator *(int k);
		Vector3 operator *(double k);
		Vector3 operator ^(Vector3 V2);

		std::string toString();
		void normalise();
	};


