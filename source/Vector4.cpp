//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2016
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


#include <Vector4.h>

Vector4::Vector4():
m_x(0),
m_y(0),
m_z(0),
m_w(0)
{}

Vector4::Vector4(const Vector3 &rhs):
m_x(rhs.GetX()),
m_y(rhs.GetY()),
m_z(rhs.GetZ()),
m_w(0)
{}

Vector4::Vector4(const float x, const float y, const float z, const float w):
m_x(x),
m_y(y),
m_z(z),
m_w(w)
{}

Vector4::Vector4(const Vector4 &rhs):
m_x(rhs.m_x),
m_y(rhs.m_y),
m_z(rhs.m_z),
m_w(rhs.m_w)
{}

Vector4::Vector4(Vector4 &&rhs):
m_x(rhs.m_x),
m_y(rhs.m_y),
m_z(rhs.m_z),
m_w(rhs.m_w)
{}

std::ostream& operator<<(std::ostream& output, const Vector4& rhs)
{
  output << "x = " 
    << rhs.m_x
    << " y = "
    << rhs.m_y
    << " z = " 
    << rhs.m_z
    << " w = " 
    << rhs.m_w
    << std::endl;
  return output;
}
Vector4 &Vector4::operator=(const Vector4 &rhs)
{
  if (this != &rhs)
  {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;
    m_w = rhs.m_w;
  }
  return *this;
}

Vector4 &Vector4::operator=(Vector4 &&rhs)
{
  if (this != &rhs)
  {
    m_x = std::move(rhs.m_x);
    m_y = rhs.m_y;
    m_z = rhs.m_z;
    m_w = rhs.m_w;
    
    rhs.m_y = 0;
    rhs.m_z = 0;
    rhs.m_w = 0;
  }
  return *this;
}

bool Vector4::operator==(const Vector4 &v1) const
{
  return m_x == v1.m_x &&
    m_y == v1.m_y &&
    m_z == v1.m_z &&
    m_w == v1.m_w;
}

bool Vector4::IsZero() const
{
  return m_x == 0 && m_y == 0 && m_z == 0 && m_w == 0 ? true : false;
}

float Vector4::Dot(const Vector4& rhs)
{
  return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z + m_w * rhs.m_w;
}
