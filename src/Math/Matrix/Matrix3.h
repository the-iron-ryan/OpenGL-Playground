#ifndef ENGINE_MATRIX_3
#define ENGINE_MATRIX_3

#include "Math/Vector/Vector3.h"
#include "Math/Vector/Vector2.h"

namespace Math
{
	//MATRIX3 FORMAT
	/*

	Basis Vector#: (0),(1),(2)
	...........(x)| 1 , 0 , 0 |
	...........(y)| 0 , 1 , 0 |
	...........(z)| 0 , 0 , 1 |
	*/
	
	//TODO: ADD DETERMINANT METHOD
    struct Matrix3
	{
		Vector3 basisVector0;
		Vector3 basisVector1;
		Vector3 basisVector2;

		explicit inline Matrix3(float r0c0 = 1.0f, float r0c1 = 0.0f, float r0c2 = 0.0f,
								float r1c0 = 0.0f, float r1c1 = 1.0f, float r1c2 = 0.0f, 
								float r2c0 = 0.0f, float r2c1 = 0.0f, float r2c2 = 1.0f);
		inline Matrix3(float values[3][3]);
		inline Matrix3(Vector3 basisVector0, Vector3 basisVector1, Vector3 basisVector2);

		inline static Matrix3 rotateZ(float radians);
		inline static Matrix3 translate(float x, float y);
		inline static Matrix3 translate(Vector3 offset);
		
		inline Vector3 Determinant();
		inline Vector3& operator[](int index);
		inline Vector3 operator[](int index) const;
	};
	inline Vector3 operator*(const Matrix3& matrix, const Vector3& vector);
	inline Matrix3 operator*(const Matrix3& left, const Matrix3& right);
	inline std::ostream& operator<<(std::ostream& os, const Matrix3& matrix);
#include "Matrix3.inl"
}

#endif

