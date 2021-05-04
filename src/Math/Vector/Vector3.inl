Vector3& Vector3::operator+=(const Vector3 &vec)
{
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3 &vec)
{
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	this->z = this->z - vec.z;
	return *this;
}
Vector3& Vector3::operator*=(float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	return *this;
}
Vector3& Vector3::operator/=(float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	this->z = this->z / scalar;
	return *this;
}
Vector3& Vector3::operator&=(const Vector3 &vec)
{
	float tempX = this->x;
	float tempY = this->y;
	float tempZ = this->z;
	this->x = tempY * vec.z - tempZ * vec.y;
	this->y = tempZ * vec.x - tempX * vec.z;
	this->z = tempX * vec.y - tempY * vec.x;
	return *this;
}
Vector3 Vector3::Cross(const Vector3 &vec)
{
	return *this & vec;
}
Vector3& Vector3::CrossEquals(const Vector3 &vec)
{
	return *this &= vec;
}
float & Vector3::operator[](int index)
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	default:
		throw std::out_of_range("3D Vector can only have three coordinates");
		break;
	}
}

float Vector3::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	default:
		throw std::out_of_range("3D Vector can only have three coordinates");
		break;
	}
}
//non member functions
Vector3 operator+(const Vector3 &vec1, const Vector3 &vec2)
{
	return Vector3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}
Vector3 operator-(const Vector3 &vec1, const Vector3 &vec2)
{
	return Vector3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}
Vector3 operator*(float scalar, const Vector3 &vec2)
{
	return Vector3(vec2.x * scalar, vec2.y * scalar, vec2.z * scalar);
}
Vector3 operator*(const Vector3 &vec2, float scalar)
{
	return scalar * vec2;
}
float operator*(const Vector3 &vec1, const Vector3 &vec2)
{
	return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z);
}
Vector3 operator&(const Vector3 &vec1, const Vector3 &vec2)
{
	return Vector3(
		vec1.y * vec2.z - vec1.z * vec2.y,
		vec1.z * vec2.x - vec1.x * vec2.z,
		vec1.x * vec2.y - vec1.y * vec2.x);
}
std::ostream& operator<<(std::ostream& os, const Vector3& vector)
{
	os << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
	return os;
}