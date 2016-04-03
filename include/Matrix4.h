//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#pragma once
#ifndef MATRIX4_H
#define MATRIX4_H
#include <Vector3.h>
#include <Vector4.h>

  class Matrix4
  {
  public:
    Matrix4(); 
    Matrix4(const Vector3& column1, const Vector3& column2, const Vector3& column3, const Vector3& column4);
    Matrix4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4);
    Matrix4(const float x0, const float y0, const float z0, const float w0,
      const float x1, const float y1, const float z1, const float w1,
      const float x2, const float y2, const float z2, const float w2,
      const float x3, const float y3, const float z3, const float w3);

    Matrix4(const Matrix4 &rhs);
    Matrix4(Matrix4 &&rhs);

    ~Matrix4();

    friend std::ostream& operator<<(std::ostream &output, const Matrix4 &rhs);
    Matrix4& operator=(const Matrix4 &rhs);
    Matrix4& operator=(Matrix4 &&rhs);
    bool operator==(const Matrix4 &m1);
    friend bool operator==(const Matrix4 &m1, const Matrix4 &m2);
    bool operator!=(const Matrix4 &m1);
    friend bool operator!=(const Matrix4 &m1, const Matrix4 &m2);
    float operator()(const int nColumn, const int nRow) const;
    Matrix4 operator*(const float &scalar) const;
    Matrix4 operator+(const Matrix4 &rhs);

    //methods
    Matrix4 Minor();
    Matrix4& Add(const Matrix4 &rhs);
    void Adjoint();
    void Cofactor();
    Matrix4& Multiply(const Matrix4 &rhs);
    Matrix4 Multiply(const Matrix4 &rhs) const;
    Vector4 MatrixVectorProduct(const Vector3 &v1) const;
    void Transpose();
    void SetIdentity();
    void SetZero();
    //Get the inverse of  the Matrix
    Matrix4 GetInverse() const;
    //Solve for x in A * x = b.  where b is a column vector.
    Vector3 Solve(const Vector3 &vec);
    //Get determinate of this matrix
    //The determinant of a matrix will be zero if
    //An entire row is zero.
    //Two rows or columns are equal.
    //A row or column is a constant multiple of another row or column.
    float GetDeterminate() const;
    //Returns true if any of the columns are the same
    bool ColumnsAreEqual() const;
    //Returns true if any of the rowss are the same
    bool RowsAreEqual() const;
    //Returns true if any Column is all zeros
    bool IsColumnZero() const;
    //Get Column "1" of a matrix
    Vector4 GetColumn1()const { return m_column1; }
    //Get Column "2" of a matrix
    Vector4 GetColumn2()const { return m_column2; }
    //Get Column "3" of a matrix
    Vector4 GetColumn3()const { return m_column3; }
    //Get Column "4" of a matrix
    Vector4 GetColumn4()const { return m_column4; }

  protected:
  private:
    float NegativeZero(float x);

    Vector4 m_column1;
    Vector4 m_column2;
    Vector4 m_column3;
    Vector4 m_column4;
  };

#endif /* MATRIX4_H */