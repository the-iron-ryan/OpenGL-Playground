#ifndef ENGINE_VECTOR_4
#define ENGINE_VECTOR_4

#include <iostream>

namespace Math
{
    struct Vector4
	{
		float x;
		float y;
		float z;
		float w;

		explicit Vector4(float xVal = 0.0f, float yVal = 0.0f, float zVal = 0.0f, float wVal = 0.0f);
		inline Vector4& operator+=(const Vector4 &vec1);
		inline Vector4& operator-=(const Vector4 &vec1);
		inline Vector4& operator*=(float scalar);
		inline Vector4& operator/=(float scalar);
		inline Vector4& operator&=(const Vector4 &vec);
		inline Vector4 Cross(const Vector4 &vec);
		inline Vector4& CrossEquals(const Vector4 &vec);
		inline float & operator[](int index);
		inline float operator[](int index) const;
	};
	inline Vector4 operator+(const Vector4 &vec1, const Vector4 &vec2);
	inline Vector4 operator-(const Vector4 &vec1, const Vector4 &vec2);
	inline Vector4 operator*(float scalar, const Vector4 &vec2);
	inline Vector4 operator*(const Vector4 &vec2, float scalar);
	inline Vector4 operator&(const Vector4 &vec1, const Vector4 &vec2);
	inline float operator*(const Vector4 &vec1, const Vector4 &vec2);
	inline std::ostream& operator<<(std::ostream& os, const Vector4& vector);
#include "Vector4.inl"

}
#endif // !ENGINE_VECTOR_4
