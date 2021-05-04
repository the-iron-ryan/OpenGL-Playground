#ifndef ENGINE_MATRIX_2H
#define ENGINE_MATRIX_2H

#include "Math/Vector/Vector2.h"
#include "Math/Vector/Vector3.h"

namespace Math
{
	//MATRIX2H FORMAT
	/*

	Basis Vector#: (0),(1),(2)
	...........(x)| 1 , 0 , 0 |
	...........(y)| 0 , 1 , 0 |
	*/
    struct Matrix2H
	{
		Vector2 basisVector0;
		Vector2 basisVector1;
		Vector2 basisVector2;

		explicit inline Matrix2H(float r0c0 = 1.0f, float r0c1 = 0.0f, float r0c2 = 0.0f,
								 float r1c0 = 0.0f, float r1c1 = 1.0f, float r1c2 = 0.0f);
		inline Matrix2H(float values[2][3]);
		inline Matrix2H(Vector2 basisVector0, Vector2 basisVector1, Vector2 basisVector2);

		inline static Matrix2H rotateZ(float radians);
		inline static Matrix2H translate(float x, float y);
		inline static Matrix2H translate(Vector2 offset);

		inline Vector2& operator[](int index);
		inline Vector2 operator[](int index) const;
	};
	inline Vector2 operator*(const Matrix2H& matrix, const Vector2& vector);
	inline Matrix2H operator*(const Matrix2H& left, const Matrix2H& right);
	inline std::ostream& operator<<(std::ostream& os, const Matrix2H& matrix);

#include "Matrix2H.inl"
}

#endif

