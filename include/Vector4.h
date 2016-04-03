//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2016
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#pragma once
#ifndef VECTOR4_H
#define VECTOR4_H
#include <Vector3.h>
class Vector4
{
public:
  Vector4();
  Vector4(const Vector3 &v1);
  Vector4(const float x, const float y, const float z, const float w);
  Vector4(const Vector4 &rhs);
  Vector4(Vector4 &&rhs);
  friend std::ostream& operator<<(std::ostream& output, const Vector4& rhs);
  Vector4& operator=(const Vector4 &rhs);
  Vector4& operator=(Vector4 &&rhs);
  bool operator==(const Vector4 &v1) const;
  bool IsZero() const;
  float Dot(const Vector4& rhs);
  float m_x;
  float m_y;
  float m_z;
  float m_w;
};
#endif /* VECTOR4_H */
