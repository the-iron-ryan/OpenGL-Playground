#ifndef ENGINE_VECTOR_2
#define ENGINE_VECTOR_2

#include <iostream>

namespace Math
{
    struct Vector2
	{
		float x;
		float y;
		explicit Vector2(float xVal = 0.0f, float yVal = 0.0f) : x(xVal), y(yVal) {}
		inline Vector2& operator+=(const Vector2 &vec1);
		inline Vector2& operator-=(const Vector2 &vec1);
		inline Vector2& operator*=(float scalar);
		inline Vector2& operator/=(float scalar);
		inline float & operator[](int index);
		inline float operator[](int index) const;
	};
	inline Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2);
	inline Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2);
	inline Vector2 operator*(float scalar, const Vector2 &vec2);
	inline Vector2 operator*(const Vector2 &vec2, float scalar);
	inline float operator*(const Vector2 &vec1, const Vector2 &vec2);
	inline std::ostream& operator<<(std::ostream& os, const Vector2& vector);

	#include "Vector2.inl"

}

#endif
