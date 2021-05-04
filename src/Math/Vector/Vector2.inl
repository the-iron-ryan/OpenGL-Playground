Vector2& Vector2::operator+=(const Vector2 &vec)
{
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	return *this;
}
Vector2& Vector2::operator-=(const Vector2 &vec)
{
	this->x = this->x - vec.x;
	this->y = this->y - vec.y;
	return *this;
}
Vector2& Vector2::operator*=(float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	return *this;
}
Vector2& Vector2::operator/=(float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	return *this;
}
float & Vector2::operator[](int index)
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	default:
		throw std::out_of_range ("2D Vector can only have two coordinates");
		break;
	}
}

float Vector2::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	default:
		throw std::out_of_range("2D Vector can only have two coordinates");
		break;
	}
}
//non member functions
Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2)
{
	return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
}
Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2)
{
	return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}
Vector2 operator*(float scalar, const Vector2 &vec2)
{
	return Vector2(vec2.x * scalar, vec2.y * scalar);
}
Vector2 operator*(const Vector2 &vec2, float scalar)
{
	return scalar * vec2;
}
float operator*(const Vector2 &vec1, const Vector2 &vec2)
{
	return (vec1.x*vec2.x) + (vec1.y*vec2.y);
}
std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	os << "<" << vector.x << ", " << vector.y << ">";
	return os;
}