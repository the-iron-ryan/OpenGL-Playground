Matrix2H::Matrix2H(
	float r0c0, float r0c1, float r0c2,
	float r1c0, float r1c1, float r1c2)
{
	this->basisVector0 = Vector2(r0c0, r1c0);
	this->basisVector1 = Vector2(r0c1, r1c1);
	this->basisVector2 = Vector2(r0c2, r1c2);
}
Matrix2H::Matrix2H(float values[2][3])
{
	//reorganized for optimal cache hits
	this->basisVector0 = Vector2();
	this->basisVector0.x = values[0][0];

	this->basisVector1 = Vector2();
	this->basisVector1.x = values[0][1];

	this->basisVector2 = Vector2();
	this->basisVector2.x = values[0][2];

	this->basisVector0.y = values[1][0];

	this->basisVector1.y = values[1][1];

	this->basisVector2.y = values[1][2];
}
Matrix2H::Matrix2H(Vector2 basisVector0, Vector2 basisVector1, Vector2 basisVector2)
{
	this->basisVector0 = basisVector0;
	this->basisVector1 = basisVector1;
	this->basisVector2 = basisVector2;
}
Vector2 & Matrix2H::operator[](int index)
{
	switch (index)
	{
	case 0:
		return this->basisVector0;
		break;
	case 1:
		return this->basisVector1;
		break;
	case 2:
		return this->basisVector2;
		break;
	default:
		throw std::out_of_range("2DH Matrix can only have a max of three Vectors");
		break;
	}
}
Vector2 Matrix2H::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return this->basisVector0;
		break;
	case 1:
		return this->basisVector1;
		break;
	case 2:
		return this->basisVector2;
		break;
	default:
		throw std::out_of_range("2DH Matrix can only have a max of three Vectors");
		break;
	}
}
Matrix2H Matrix2H::translate(float x, float y)
{
	return Matrix2H(
		1.0f, 0.0f,	   x,
		0.0f, 1.0f,	   y);
}
Matrix2H Matrix2H::translate(Vector2 offset)
{
	return Matrix2H(
		1.0f, 0.0f, offset.x,
		0.0f, 1.0f, offset.y);
}
Matrix2H Matrix2H::rotateZ(float radians)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix2H(
		cosResult, -sinResult,  0.0f,
		sinResult,  cosResult,	0.0f);
}
//non member functions
Vector2 operator*(const Matrix2H& matrix, const Vector3& vector)
{
	return Vector2(
		matrix[0][0] * vector.x + matrix[1][0] * vector.y + matrix[2][0] * vector.z,
		matrix[0][1] * vector.x + matrix[1][1] * vector.y + matrix[2][1] * vector.z);
}
Matrix2H operator*(const Matrix2H& left, const Matrix2H& right)
{
	return Matrix2H(
		left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
		left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
		left[0][0] * right[2][0] + left[1][0] * right[2][1] + left[2][0] * right[2][2],

		left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],
		left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
		left[0][1] * right[2][0] + left[1][1] * right[2][1] + left[2][1] * right[2][2]);

}

std::ostream& operator<<(std::ostream& os, const Matrix2H& matrix)
{
	os << std::endl;
	os << "| " << matrix[0][0] << ", " << matrix[1][0] << ", " << matrix[2][0] << " |" << std::endl;
	os << "| " << matrix[0][1] << ", " << matrix[1][1] << ", " << matrix[2][1] << " |" << std::endl;
	return os;
}