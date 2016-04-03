//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#pragma once
#ifndef MATRIX2_H
#define MATRIX2_H
#include <Vector2.h>

  //TODO Documentation doxygen style
  //TODO Add a function that turns the columns into rows. 
  class Matrix2
  {
  public:
    Matrix2();
    Matrix2(const Vector2& vector1, const Vector2& vector2);
    Matrix2(float x0, float y0, float x1, float y1);
    
    Matrix2(const Matrix2 &rhs);
    Matrix2(Matrix2 &&rhs);
    
    ~Matrix2();
    //TODO write == operator
    friend std::ostream& operator<<(std::ostream& output, const Matrix2& rhs);
    Matrix2& operator=(const Matrix2 &rhs);
    Matrix2& operator=(Matrix2 &&rhs);

    float operator()(const int nColumn, const int nRow) const;
    Matrix2 operator*(const float &scalar);
    Matrix2 operator+(const Matrix2 &rhs);
    bool operator==(const Matrix2 &m1);
    friend bool operator==(const Matrix2 &m1, const Matrix2 &m2);
    bool operator!=(const Matrix2 &m1);
    friend bool operator!=(const Matrix2 &m1, const Matrix2 &m2);

    //methods
    Matrix2 Add(const Matrix2 &rhs);
    void Adjoint();
    void Cofactor();
    Matrix2 Multiply(const Matrix2 &rhs);
    void Transpose();
    void SetIdentity();
    void SetZero();
    //Get the inverse of  the Matrix
    Matrix2 GetInverse() const;
    //Solve for x in A * x = b.  where b is a column vector.
    Vector2 Solve(const Vector2 &vec);
    //Get determinate of this matrix
    float GetDeterminate() const;
    //Get vector "1" of a matrix
    Vector2 GetColumn1() const { return column1; }
    //Get vetor "2" of a matrix
    Vector2 GetColumn2() const { return column2; }

  protected:
  private:
    Vector2 column1;
    Vector2 column2;
  };
  //Multiply a Matrix times a vector.
  Vector2 operator*(const Matrix2 &mat, Vector2 &vec);
  //Multiply a Matrix times a Matrix.
  Matrix2 operator*(const Matrix2 &mat1, const Matrix2 &matrix2);
  //Multiply a Matrix times a Scalar.
  Matrix2 operator*(const float &scalar, const Matrix2& rhs);

#endif /* MATRIX2_H */
