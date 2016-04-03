//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H
#include <IVector.h>


  class Vector3 : public IVector<Vector3>
  {

  public:
    Vector3();
    Vector3(const float x, const float y, const float z);

    Vector3(const Vector3 &rhs);
    Vector3(Vector3 &&rhs);

    virtual ~Vector3();

    Vector3& operator=(const Vector3& rhs);
    Vector3& operator=(Vector3&& rhs);

    friend std::ostream& operator<<(std::ostream& output, const Vector3& rhs);
    friend std::istream& operator>>(std::istream& input, Vector3& lhs);

    //arithmetic operators
    //Add a vector to this vector
    Vector3 operator+(const Vector3 &rhs);
    Vector3 operator+(const Vector3 &rhs) const;
    void operator+=(const Vector3 &rhs);
    void operator+=(const int &x);

    //Subtract a vector from this vector
    Vector3 operator-(const Vector3& rhs);
    void operator-=(const Vector3& rhs);

    //Multiply this vector times a scalar.
    Vector3 operator*(const float scalar);
    Vector3 operator*(const float scalar) const;
    void operator*=(const float scalar);
    bool operator==(const Vector3 &v1);
    friend bool operator==(const Vector3 &v1, const Vector3 &v2);
    bool operator!=(const Vector3 &v1);
    friend bool operator!=(const Vector3 &v1, const Vector3 &v2);
    float& operator[](const int nIndex);

    void AddScaledVector(const Vector3& vector, float scalar);
    Vector3 Product(const Vector3& vector);
    void ProductUpdate(const Vector3& vector);

    float Magnitude() const;
    float SquaredMagnitude() const;
    float Dot(const Vector3& rhs);
    float Dot(const Vector3 &rhs) const;
    float Angle(const Vector3& rhs);
    Vector3 Projection(const Vector3& rhs);
    float Max() const;
    float Min() const;

    bool IsZero() const;
    //in 2d this produces a scalar
    Vector3 Cross(const Vector3& rhs);
    //make "unit" vector
    void Normalize();

    //sets
    void SetZero();
    void SetVector(const float x, const float y, const float z);
    void Negate();
    void SetX(const float x){ m_x = x; }
    void SetY(const float y){ m_y = y; }
    void SetZ(const float z){ m_z = z; }

    float GetX() const { return m_x; }
    float GetY() const { return m_y; }
    float GetZ() const { return m_z; }

    const static Vector3 GRAVITY;
    const static Vector3 ORIGIN;
    const static Vector3 X;
    const static Vector3 Y;
    const static Vector3 Z;

    float m_x;
    float m_y;
    float m_z;
  private:
    float operator()(tuint32 i) const;
    float& operator()(tuint32 i);


  };
  Vector3 Normalize(const Vector3& rhs);
#endif /* VECTOR3_H */
