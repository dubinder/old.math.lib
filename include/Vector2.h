//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H
#include <IVector.h>

  class Vector2 : public IVector<Vector2>
  {
  public:
    //constructors
    Vector2();
    Vector2(const float x, const float y);
    Vector2(const Vector2 &rhs);
    Vector2(Vector2 &&rhs);

    //destructor
    ~Vector2();

    Vector2& operator=(const Vector2& rhs);
    Vector2& operator=(Vector2 &&rhs);

    //friend std::ostream& operator<<(std::ostream& output, const Vector2& rhs);
    //friend std::istream& operator>>(std::istream& input, Vector2& lhs);


    //Add a vector to this vector
    Vector2 operator+(const Vector2& rhs);
    void operator+=(const Vector2& rhs);

    //Subtract a vector from this vector
    Vector2 operator-(const Vector2& rhs);
    void operator-=(const Vector2& rhs);

    //Multiply this vector times a scalar.
    Vector2 operator*(const float scalar);
    void operator*=(const float scalar);
    float& operator[](const int nIndex);

    bool operator==(const Vector2 &v1);
    friend bool operator==(const Vector2 &v1, const Vector2 &v2);
    bool operator!=(const Vector2 &v1);
    friend bool operator!=(const Vector2 &v1, const Vector2 &v2);

    float Angle(const Vector2& rhs){ return 1.0f; };
    virtual Vector2 Cross(const Vector2& rhs){ return Vector2(); };
    /// \brief The dot product of a A.Dot(B)
    /// \param rhs the reference to the Vector that is being dotted with *this
    /// \return float
    ///
    /// This will return the value of the dot product of two vectors A B
    float Dot(const Vector2& rhs);

    /// \brief Is the Vector all Zero
    /// \param
    /// \return bool
    ///
    /// This will return true if all the values of the Vector are zero
    /// false otherwise
    bool IsZero() const;

    /// \brief Negate a Vector
    /// \param
    /// \return void
    ///
    /// This will negate all the Values of the Vector
    void Negate();

    /// \brief This will normal the vector
    /// \param
    /// \return void
    ///
    /// This will set the current vector to the unit version of itself
    void Normalize();
    float Magnitude() const;
    float Max() const;
    float Min() const;
    Vector2 Projection(const Vector2& rhs){ return Vector2(); };
    void SetZero();
    void SetVector(const float _x, const float _y);
    float SquaredMagnitude() const;

    float GetX() const { return m_x; }
    float GetY() const { return m_y; }

    float m_x;
    float m_y;

  private:
    float operator()(const int i) const;
    float& operator()(const int i);
  };
#endif /* VECTOR2_H */
