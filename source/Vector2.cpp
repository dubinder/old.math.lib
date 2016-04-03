//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <Vector2.h>

#pragma region constructors
Vector2::Vector2():
  m_x(0),
  m_y(0)
{}

Vector2::Vector2(const float x, const float y):
  m_x(x),
  m_y(y)
{}

Vector2::Vector2(const Vector2& rhs):
  m_x(rhs.m_x),
  m_y(rhs.m_y)
{}

Vector2::Vector2(Vector2&& rhs) :
  m_x(0),
  m_y(0)
{
  m_x = rhs.m_x;
  m_y = rhs.m_y;
}

//destructor
Vector2::~Vector2(){}

//copy assignment
Vector2& Vector2::operator=(const Vector2& rhs)
{
  if (this != &rhs)
  {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
  }
  return *this;
}

//move assignment
Vector2& Vector2::operator=(Vector2 &&rhs)
{
  if (this != &rhs)
  {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    rhs.m_x = 0;
    rhs.m_y = 0;
  }
  return *this;
}
#pragma endregion Constructors

#pragma region operators
std::ostream& operator<<(std::ostream& output, const Vector2& rhs)
{
  output << "m_x = "
    << rhs.m_x
    << ", "
    << "m_y = "
    << rhs.m_y
    << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Vector2& lhs)
{
  input >> lhs.m_x
    >> lhs.m_y;
  return input;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
  return Vector2(m_x + rhs.m_x, m_y + rhs.m_y);
}

void Vector2::operator+=(const Vector2& rhs)
{
  m_x += rhs.m_x;
  m_y += rhs.m_y;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
  return (Vector2(m_x - rhs.m_x, m_y - rhs.m_y));
}

void Vector2::operator-=(const Vector2& rhs)
{
  m_x -= rhs.m_x;
  m_y -= rhs.m_y;
}

Vector2 Vector2::operator*(const float s)
{
  return Vector2(m_x * s, m_y * s);
}

void Vector2::operator*=(const float scalar)
{
  m_x *= scalar;
  m_y *= scalar;
}

float& Vector2::operator[](const int nIndex)
{
  return this->operator()(nIndex);
}

bool Vector2::operator==(const Vector2 &v1)
{
  return m_x == v1.m_x &&
    m_y == v1.m_y;
}

bool operator==(const Vector2 &v1, const Vector2 &v2)
{
  return v1.m_x == v2.m_x &&
    v1.m_y == v2.m_y;
}

bool Vector2::operator!=(const Vector2 &v1)
{
  return !(*this == v1);
}

bool operator!=(const Vector2 &v1, const Vector2 &v2)
{
  return !(v1 == v2);
}

float Vector2::operator()(const int i) const
{
  //TODO maybe make sure it is 0 or Greater
  assert(i < 2);
  return (&m_x)[i];
}

float& Vector2::operator()(const int i)
{
  assert(i < 2);
  return (&m_x)[i];
}
#pragma endregion Operators

#pragma region methods
float Vector2::Magnitude() const
{
  return sqrt(m_x * m_x + m_y * m_y);
}

float Vector2::SquaredMagnitude() const
{
  return m_x * m_x + m_y * m_y;
}

float Vector2::Dot(const Vector2 &rhs)
{
  return m_x * rhs.m_x + m_y * rhs.m_y;
}

float Vector2::Max() const
{
  return (m_x < m_y) ? m_y : m_x;
}

float Vector2::Min() const
{
  return (m_x < m_y) ? m_x : m_y;
}

bool Vector2::IsZero() const
{
  return m_x == 0 && m_y == 0 ? true : false;
}

void Vector2::Normalize()
{
  float length = Magnitude();
  if (length < FLT_EPSILON)
  {
    return;
  }
  float invLength = 1.0f / length;
  m_x *= invLength;
  m_y *= invLength;
}
#pragma endregion Methods
//sets
void Vector2::SetZero()
{
  m_x = 0;
  m_y = 0;
}

void Vector2::SetVector(const float _x, const float _y)
{
  m_x = _x;
  m_y = _y;
}

void Vector2::Negate()
{
  m_x = -m_x;
  m_y = -m_y;
}
