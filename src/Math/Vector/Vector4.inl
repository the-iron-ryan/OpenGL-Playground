Vector4& Vector4::operator+=(const Vector4 &vec)
{
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;
	this->w = this->w + vec.w;
	return *this;
}
Vector4& Vector4::operator-=(const Vector4 &vec)
{
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	this->z = this->z - vec.z;
	this->w = this->w - vec.w;
	return *this;
}
Vector4& Vector4::operator*=(float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	this->w = this->w * scalar;
	return *this;
}
Vector4& Vector4::operator/=(float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	this->z = this->z / scalar;
	this->w = this->w / scalar;
	return *this;
}
//Vector4& Vector4::operator&=(const Vector4 &vec)
//{
//	float tempX = this->x;
//	float tempY = this->y;
//	float tempZ = this->z;
//	float tempW = this->w;
//	this->x = tempY * vec.z - tempZ * vec.y;
//	this->y = tempZ * vec.x - tempX * vec.z;
//	this->z = tempX * vec.y - tempY * vec.x;
//	this->w = tempX * vec.y - tempY * vec.x;
//	return *this;
//}
//Vector4 Vector4::Cross(const Vector4 &vec)
//{
//	return *this & vec;
//}
//Vector4& Vector4::CrossEquals(const Vector4 &vec)
//{
//	return *this &= vec;
//}
float & Vector4::operator[](int index)
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
	case 3:
		return this->w;
		break;
	default:
		throw std::out_of_range("4D Vector can only have four coordinates");
		break;
	}
}

float Vector4::operator[](int index) const
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
	case 3:
		return this->w;
		break;
	default:
		throw std::out_of_range("4D Vector can only have four coordinates");
		break;
	}
}
//non member functions
Vector4 operator+(const Vector4 &vec1, const Vector4 &vec2)
{
	return Vector4(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w);
}
Vector4 operator-(const Vector4 &vec1, const Vector4 &vec2)
{
	return Vector4(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w);
}
Vector4 operator*(float scalar, const Vector4 &vec2)
{
	return Vector4(vec2.x * scalar, vec2.y * scalar, vec2.z * scalar, vec2.w * scalar);
}
Vector4 operator*(const Vector4 &vec2, float scalar)
{
	return scalar * vec2;
}
float operator*(const Vector4 &vec1, const Vector4 &vec2)
{
	return (vec1.x*vec2.x) + (vec1.y*vec2.y) + (vec1.z*vec2.z) + (vec1.w*vec2.w);
}
//Vector4 operator&(const Vector4 &vec1, const Vector4 &vec2)
//{
//	return Vector4(
//		vec1.y * vec2.z - vec1.z * vec2.y,
//		vec1.z * vec2.x - vec1.x * vec2.z,
//		vec1.x * vec2.y - vec1.y * vec2.x);
//}
std::ostream& operator<<(std::ostream& os, const Vector4& vector)
{
	os << "<" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w <<">";
	return os;
}