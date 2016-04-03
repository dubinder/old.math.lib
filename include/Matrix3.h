//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#pragma once
#ifndef MATRIX3_H
#define MATRIX3_H
#include <Vector3.h>

  //TODO Documentation doxygen style
  //TODO Add a function that turns the columns into rows. 
  //TODO Hungarian notation.
  class BaseMatrix
  {
  public:
    Vector3 column1;
    Vector3 column2;
    Vector3 column3;
  };
  
  class Matrix3
  {
  public:
    Matrix3();
    Matrix3(const Vector3& column1, const Vector3& column2, const Vector3& column3);
    Matrix3(const float x0, const float y0, const float z0,
      const float x1, const float y1, const float z1,
      const float x2, const float y2, const float z2);
    
    Matrix3(const Matrix3 &rhs);
    Matrix3(Matrix3 &&rhs);
    
    ~Matrix3();
    
    friend std::ostream& operator<<(std::ostream &output, const Matrix3 &rhs);
    Matrix3& operator=(const Matrix3 &rhs);
    Matrix3& operator=(Matrix3 &&rhs);
    bool operator==(const Matrix3 &m1);
    friend bool operator==(const Matrix3 &m1, const Matrix3 &m2);
    bool operator!=(const Matrix3 &m1);
    friend bool operator!=(const Matrix3 &m1, const Matrix3 &m2);
    float operator()(const int nColumn, const int nRow) const;
    Matrix3 operator*(const float &scalar) const;
    Matrix3 operator+(const Matrix3 &rhs);

    //methods
    Matrix3 Minor();
    Matrix3& Add(const Matrix3 &rhs);
    void Adjoint();
    void Cofactor();
    Matrix3& Multiply(const Matrix3 &rhs);
    Matrix3 Multiply(const Matrix3 &rhs) const;
    Vector3 MatrixVectorProduct(const Vector3 &v1) const;
    void Transpose();
    void SetIdentity();
    void SetZero();
    //Get the inverse of  the Matrix
    Matrix3 GetInverse() const;
    //Solve for x in A * x = b.  where b is a column vector.
    Vector3 Solve(const Vector3 &vec);
    //Get determinate of this matrix
    float GetDeterminate() const;
    //Get Column "1" of a matrix
    Vector3 GetColumn1()const { return column1; }
    //Get Column "2" of a matrix
    Vector3 GetColumn2()const { return column2; }
    //Get Column "3" of a matrix
    Vector3 GetColumn3()const { return column3; }

  protected:
  private:
    float NegativeZero(float x);

    Vector3 column1;
    Vector3 column2;
    Vector3 column3;
  };

  //Multiply a Matrix times a vector.
  Vector3 operator*(const Matrix3 &mat, const Vector3 &vec);
  //Multiply a Matrix times a Matrix.
  Matrix3 operator*(const Matrix3 &matrix1, const Matrix3 &matrix2);
  Matrix3 operator*(const float &scalar, const Matrix3 &matrix1);

#endif /* MATRIX3_H*/
