//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <Vector3.h>

#pragma region constructors
Vector3::Vector3():
  m_x(0),
  m_y(0),
  m_z(0)
{}

Vector3::Vector3(const float x, const float y, const float z) :
  m_x(x),
  m_y(y),
  m_z(z)
{}

Vector3::Vector3(const Vector3& rhs):
  m_x(rhs.m_x),
  m_y(rhs.m_y),
  m_z(rhs.m_z)
{}

Vector3::Vector3(Vector3&& rhs):
  m_x(0),
  m_y(0),
  m_z(0)
{
  m_x = rhs.m_x;
  m_y = rhs.m_y;
  m_z = rhs.m_z;
}

//destructor
Vector3::~Vector3(){}

//copy assignment
Vector3& Vector3::operator=(const Vector3& rhs)
{
  if (this != &rhs)
  {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;
  }
  return *this;
}

//move assignment
Vector3& Vector3::operator=(Vector3&& rhs)
{
  if (this != &rhs)
  {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;
    rhs.m_x = 0;
    rhs.m_y = 0;
    rhs.m_z = 0;
  }
  return *this;
}
#pragma endregion Constructors

#pragma region operators
std::ostream& operator<<(std::ostream& output, const Vector3& rhs)
{
  output << "m_x = "
    << rhs.m_x
    << " m_y = "
    << rhs.m_y
    << " m_z = "
    << rhs.m_z
    << std::endl;
  return output;
}

std::istream& operator>>(std::istream& input, Vector3& lhs)
{
  input >> lhs.m_x
    >> lhs.m_y
    >> lhs.m_z;
  return input;
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
  return Vector3(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
  return Vector3(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

void Vector3::operator+=(const Vector3& rhs)
{
  m_x += rhs.m_x;
  m_y += rhs.m_y;
  m_z += rhs.m_z;
}

void Vector3::operator+=(const int &_x)
{
  m_x += _x;
  m_y += _x;
  m_z += _x;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
  return Vector3(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

void Vector3::operator-=(const Vector3& rhs)
{
  m_x -= rhs.m_x;
  m_y -= rhs.m_y;
  m_z -= rhs.m_z;
}

Vector3 Vector3::operator*(const float scalar)
{
  return Vector3(m_x * scalar, m_y * scalar, m_z * scalar);
}

Vector3 Vector3::operator*(const float scalar) const
{
  return Vector3(m_x * scalar, m_y * scalar, m_z * scalar);
}

void Vector3::operator*=(const float scalar)
{
  m_x *= scalar;
  m_y *= scalar;
  m_z *= scalar;
}

bool Vector3::operator==(const Vector3 &v1)
{
  return m_x == v1.m_x &&
    m_y == v1.m_y &&
    m_z == v1.m_z;
}

bool operator==(const Vector3 &v1, const Vector3 &v2)
{
  return v1.m_x == v2.m_x &&
    v1.m_y == v2.m_y &&
    v1.m_z == v2.m_z;
}

bool operator!=(const Vector3 &v1, const Vector3 &v2)
{
  return !(v1 == v2);
}

bool Vector3::operator!=(const Vector3 &v1)
{
  return !(*this == v1);
}

float& Vector3::operator[](const int nIndex)
{
  return operator()(nIndex);
}

float Vector3::operator()(tuint32 i) const
{
  //TODO Maybe check for >= 0;
  assert(i < 3);
  return (&m_x)[i];
}

float& Vector3::operator()(tuint32 i)
{
  assert(i < 3);
  return (&m_x)[i];
}
#pragma endregion Operators

#pragma region methods
void Vector3::AddScaledVector(const Vector3& vector, float scalar)
{
  m_x += vector.GetX() * scalar;
  m_y += vector.GetY() * scalar;
  m_z += vector.GetZ() * scalar;
}

Vector3 Vector3::Product(const Vector3& vector)
{
  return Vector3(m_x * vector.GetX(),
    m_y * vector.GetY(),
    m_z * vector.GetZ());
}

void Vector3::ProductUpdate(const Vector3& vector)
{
  m_x *= vector.GetX();
  m_y *= vector.GetY();
  m_z *= vector.GetZ();
}

float Vector3::Magnitude() const
{
  return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Vector3::SquaredMagnitude() const
{
  return m_x * m_x + m_y * m_y + m_z * m_z;
}

float Vector3::Dot(const Vector3 &rhs)
{
  return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
}

float Vector3::Dot(const Vector3 &rhs) const
{
  return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
}

float Vector3::Angle(const Vector3& rhs)
{
  float theta = Dot(rhs);
  if (theta == 0)
  {
    return acosf(theta);
  }
  else
    theta /= (Magnitude() * rhs.Magnitude());
  if (theta >= -1.0)
  {
    if (theta <= 1.0)
    {
      return acosf(theta);
    }
  }
}

Vector3 Vector3::Projection(const Vector3& rhs)
{
  float theta = rhs.Dot(*this)/ (rhs.Magnitude() * rhs.Magnitude());
  return rhs * theta;
}

float Vector3::Max() const
{
  float t = (m_x < m_y) ? m_y : m_x;
  return (t < m_z) ? m_z : t;
}

float Vector3::Min() const
{
  float t = (m_x < m_y) ? m_x : m_y;
  return (t < m_z) ? t : m_z;
}


bool Vector3::IsZero() const
{
  return m_x == 0 && m_y == 0 && m_z == 0 ? true : false;
}

Vector3 Vector3::Cross(const Vector3 &rhs)
{
  return Vector3(m_y * rhs.m_z - m_z * rhs.m_y,
    m_z * rhs.m_x - m_x * rhs.m_z,
    m_x * rhs.m_y - m_y * rhs.m_x);
}

void Vector3::Normalize()
{
  float magnitude = Magnitude();
  if (magnitude > 0)
  {
    m_x /= magnitude;
    m_y /= magnitude;
    m_z /= magnitude;
  }
}
#pragma endregion Methods

Vector3 Normalize(const Vector3& rhs)
{
  float magnitude = rhs.Magnitude();
  float m_x = rhs.GetX();
  float m_y = rhs.GetY();
  float m_z = rhs.GetZ();
  if (magnitude > 0)
  {
    m_x /= magnitude;
    m_y /= magnitude;
    m_z /= magnitude;
  }
  return Vector3(m_x, m_y, m_z);
}


#pragma region setters
void Vector3::SetZero()
{
  m_x = 0;
  m_y = 0;
  m_z = 0;
}

void Vector3::SetVector(float _x, float _y, float  _z)
{
  m_x = _x;
  m_y = _y;
  m_z = _z;
}

void Vector3::Negate()
{
  m_x = -m_x;
  m_y = -m_y;
  m_z = -m_z;
}
#pragma endregion Setters

