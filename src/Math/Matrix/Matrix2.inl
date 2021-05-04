Matrix2::Matrix2(float r0c0, float r0c1, float r1c0, float r1c1)
{
	basisVector0 = Vector2(r0c0, r1c0);
	basisVector1 = Vector2(r0c1, r1c1);
}
Matrix2::Matrix2(float values[2][2])
{
	basisVector0 = Vector2(values[0][0], values[1][0]);
	basisVector1 = Vector2(values[0][1], values[1][1]);
}
Vector2 & Matrix2::operator[](int index)
{
	switch (index)
	{
	case 0:
		return basisVector0;
		break;
	case 1:
		return basisVector1;
		break;
	default:
		throw std::out_of_range("2D Matrix can only have a max of two Vectors");
		break;
	}
}
Vector2 Matrix2::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return basisVector0;
		break;
	case 1:
		return basisVector1;
		break;
	default:
		throw std::out_of_range("2D Matrix can only have a max of two Vectors");
		break;
	}
}
Matrix2 Matrix2::rotate(float radians)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix2(cosResult, -sinResult,
				   sinResult,  cosResult);
}
//non member functions
Vector2 operator*(const Matrix2& matrix, const Vector2& vector)
{
	return Vector2(vector[0] * matrix[0] + vector[1] * matrix[1]);
}
std::ostream& operator<<(std::ostream& os, const Matrix2& matrix) 
{
	return os;
}