Matrix3::Matrix3(
	float r0c0, float r0c1, float r0c2,
	float r1c0, float r1c1, float r1c2,
	float r2c0, float r2c1, float r2c2)
{
	this->basisVector0 = Vector3(r0c0, r1c0, r2c0);
	this->basisVector1 = Vector3(r0c1, r1c1, r2c1);
	this->basisVector2 = Vector3(r0c2, r1c2, r2c2);
}
Matrix3::Matrix3(float values[3][3])
{
	//reorganized for optimal cache hits
	this->basisVector0 = Vector3();
	this->basisVector0.x = values[0][0];

	this->basisVector1 = Vector3();
	this->basisVector1.x = values[0][1];

	this->basisVector2 = Vector3();
	this->basisVector2.x = values[0][2];

	this->basisVector0.y = values[1][0];

	this->basisVector1.y = values[1][1];

	this->basisVector2.y = values[1][2];


	this->basisVector0.z = values[2][0];

	this->basisVector1.z = values[2][1];

	this->basisVector2.z = values[2][2];
}
Matrix3::Matrix3(Vector3 basisVector0, Vector3 basisVector1, Vector3 basisVector2)
{
	this->basisVector0 = basisVector0;
	this->basisVector1 = basisVector1;
	this->basisVector2 = basisVector2;
}
Vector3 Matrix3::Determinant() {
	/*
	Determinant Matrix Format
		   ^   ^   ^
		|  x,  y,  z |
		| u1, u2, u3 |
		| v1, v2, v3 |
	*/
	Vector3 u(basisVector0.y, basisVector1.y, basisVector2.y);
	Vector3 v(basisVector0.z, basisVector1.z, basisVector2.z);

	return Vector3(
		basisVector0.x * (u.y * v.z - u.z * v.y), 
		basisVector0.y * (u.z * v.x - u.x * v.z),
		basisVector0.z * (u.x * v.y - u.y * v.x));
}
Vector3 & Matrix3::operator[](int index)
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
		throw std::out_of_range("3D Matrix can only have a max of three Vectors");
		break;
	}
}
Vector3 Matrix3::operator[](int index) const
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
		throw std::out_of_range("3D Matrix can only have a max of three Vectors");
		break;
	}
}
Matrix3 Matrix3::translate(float x, float y)
{
	return Matrix3(
		1.0f, 0.0f,	   x,
		0.0f, 1.0f,	   y,
		0.0f, 0.0f, 1.0f);
}
Matrix3 Matrix3::translate(Vector3 offset)
{
	return Matrix3(
		1.0f, 0.0f, offset.x,
		0.0f, 1.0f, offset.y,
		0.0f, 0.0f,		1.0f);
}
Matrix3 Matrix3::rotateZ(float radians)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix3(
		cosResult, -sinResult,  0.0f,
		sinResult,  cosResult,	0.0f,
			 0.0f,		 0.0f,	1.0f);
}
//non member functions
Vector3 operator*(const Matrix3& matrix, const Vector3& vector)
{
	return Vector3(
		matrix[0][0] * vector.x + matrix[1][0] * vector.y + matrix[2][0] * vector.z,
		matrix[0][1] * vector.x + matrix[1][1] * vector.y + matrix[2][1] * vector.z,
		matrix[0][2] * vector.x + matrix[1][2] * vector.y + matrix[2][2] * vector.z
	);
}
Matrix3 operator*(const Matrix3& left, const Matrix3& right)
{
	return Matrix3(
		left[0][0] * right[0][0] + left[1][0] * right[0][1] + left[2][0] * right[0][2],
		left[0][0] * right[1][0] + left[1][0] * right[1][1] + left[2][0] * right[1][2],
		left[0][0] * right[2][0] + left[1][0] * right[2][1] + left[2][0] * right[2][2],

		left[0][1] * right[0][0] + left[1][1] * right[0][1] + left[2][1] * right[0][2],
		left[0][1] * right[1][0] + left[1][1] * right[1][1] + left[2][1] * right[1][2],
		left[0][1] * right[2][0] + left[1][1] * right[2][1] + left[2][1] * right[2][2],

		left[0][2] * right[0][0] + left[1][2] * right[0][1] + left[2][2] * right[0][2],
		left[0][2] * right[1][0] + left[1][2] * right[1][1] + left[2][2] * right[1][2],
		left[0][2] * right[2][0] + left[1][2] * right[2][1] + left[2][2] * right[2][2]);

}

std::ostream& operator<<(std::ostream& os, const Matrix3& matrix)
{
	os << std::endl;
	os << "| " << matrix[0][0] << ", " << matrix[1][0] << ", " << matrix[2][0] << " |" << std::endl;
	os << "| " << matrix[0][1] << ", " << matrix[1][1] << ", " << matrix[2][1] << " |" << std::endl;
	os << "| " << matrix[0][2] << ", " << matrix[1][2] << ", " << matrix[2][2] << " |" << std::endl;
	return os;
}