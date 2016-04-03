//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#pragma once
#ifndef IVECTOR_H
#define IVECTOR_H
  /// \class IVector
  /// \brief A IVector Base class
  /// \author Dylan Binder
  ///
  /// This is a base class to define the interface of the Vector API
  template<typename T>
  class IVector
  {
  public:
    virtual ~IVector() {};

    friend std::ostream& operator<<(std::ostream& output, const T& rhs);
    friend std::istream& operator>>(std::istream& input, T& lhs);

    /// \brief Add a Vector to this Vector
    virtual T operator+(const T& rhs) = 0;
    virtual void operator+=(const T& rhs) = 0;

    /// \breif Subtract a Vector from this Vector
    virtual T operator-(const T& rhs) = 0;
    virtual void operator-=(const T& rhs) = 0;

    /// \breif Multiply this Vector times a scalar.
    virtual T operator*(const float scalar) = 0;
    virtual void operator*=(const float scalar) = 0;

    virtual float& operator[](const int nIndex) = 0;

    virtual bool operator==(const T &rhs) = 0;
    virtual bool operator!=(const T &rhs) = 0;

    virtual float Angle(const T& rhs) = 0;

    /// \brief The Cross product of a vector
    /// \param rhs the reference to the Vector that is being crossed with *this
    /// \return Vector
    ///
    /// This will return the Vector of the cross product, however in 2D this will return and empty
    /// Vector.
    virtual T Cross(const T& rhs) = 0;
    /// \brief The dot product of a A.Dot(B)
    /// \param rhs the reference to the Vector that is being dotted with *this
    /// \return float
    ///
    /// This will return the value of the dot product of two vectors A B
    virtual float Dot(const T& rhs) = 0;

    /// \brief Is the Vector all Zero
    /// \param
    /// \return bool
    ///
    /// This will return true if all the values of the Vector are zero
    /// false otherwise
    virtual bool IsZero() const = 0;

    /// \brief Negate a Vector
    /// \param
    /// \return void
    ///
    /// This will negate all the Values of the Vector
    virtual void Negate() = 0;

    /// \brief This will normal the vector
    /// \param
    /// \return void
    ///
    /// This will set the current vector to the unit version of itself
    virtual void Normalize() = 0;
    virtual float Magnitude() const = 0;
    virtual float Max() const = 0;
    virtual float Min() const = 0;
    virtual T Projection(const T& rhs) = 0;
    virtual void SetZero() = 0;
    virtual float SquaredMagnitude() const = 0;



  };
#endif /* IVECTOR_H */
