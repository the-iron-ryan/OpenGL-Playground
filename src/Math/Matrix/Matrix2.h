#ifndef ENGINE_MATRIX_2
#define ENGINE_MATRIX_2

#include "Math/Vector/Vector2.h"

namespace Math 
{
	//MATRIX2 FORMAT
	/*

	Basis Vector#: (0),(1)
	...........(x)| 1 , 0 |
	...........(y)| 0 , 1 |
	
	*/
    struct Matrix2
	{
		Vector2 basisVector0;
		Vector2 basisVector1;

		explicit inline Matrix2(float r0c0 = 1.0f, float r0c1 = 0.0f, float r1c0 = 0.0f, float r1c1 = 1.0f);
		inline Matrix2(float values[2][2]);

		inline static Matrix2 rotate(float radians);
		
		inline Vector2& operator[](int index);
		inline Vector2 operator[](int index) const;
	};
	inline Vector2 operator*(const Matrix2& matrix, const Vector2& vector);
	inline std::ostream& operator<<(std::ostream& os, const Matrix2& matrix);
	#include "Matrix2.inl"
}

#endif

