#ifndef ENGINE_VECTOR_3
#define ENGINE_VECTOR_3

#include <iostream>

namespace Math
{
    struct Vector3
	{
		float x;
		float y;
		float z;

		explicit Vector3(float xVal = 0.0f, float yVal = 0.0f, float zVal = 0.0f) : x(xVal), y(yVal), z(zVal) {}
		inline Vector3& operator+=(const Vector3 &vec1);
		inline Vector3& operator-=(const Vector3 &vec1);
		inline Vector3& operator*=(float scalar);
		inline Vector3& operator/=(float scalar);
		inline Vector3& operator&=(const Vector3 &vec);
		inline Vector3 Cross(const Vector3 &vec);
		inline Vector3& CrossEquals(const Vector3 &vec);
		inline float & operator[](int index);
		inline float operator[](int index) const;
	};
	inline Vector3 operator+(const Vector3 &vec1, const Vector3 &vec2);
	inline Vector3 operator-(const Vector3 &vec1, const Vector3 &vec2);
	inline Vector3 operator*(float scalar, const Vector3 &vec2);
	inline Vector3 operator*(const Vector3 &vec2, float scalar);
	inline Vector3 operator&(const Vector3 &vec1, const Vector3 &vec2);
	inline float operator*(const Vector3 &vec1, const Vector3 &vec2);
	inline std::ostream& operator<<(std::ostream& os, const Vector3& vector);

#include "Vector3.inl"

}

#endif
