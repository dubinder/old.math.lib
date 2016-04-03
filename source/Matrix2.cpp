//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <Matrix2.h>

#pragma region Constructors
Matrix2::Matrix2() = default;

Matrix2::Matrix2(const Vector2& first, const Vector2& second):
column1(first),
column2(second)
{}

Matrix2::Matrix2(float x0, float y0, float x1, float y1) :
  column1(x0, y0),
  column2(x1, y1)
{}

Matrix2::Matrix2(const Matrix2 &rhs):
  column1(rhs.column1),
  column2(rhs.column2)
{}

Matrix2::Matrix2(Matrix2 &&rhs)
{
  column1 = rhs.column1;
  column2 = rhs.column2;
  rhs.column1.SetZero();
  rhs.column2.SetZero();
}
#pragma endregion Constructors

//destructor
Matrix2::~Matrix2(){}

//copy assignment
Matrix2& Matrix2::operator=(const Matrix2 &rhs)
{
  if (this != &rhs)
  {
    column1 = rhs.column1;
    column2 = rhs.column2;
  }
  return *this;
}

//move assignment
Matrix2& Matrix2::operator=(Matrix2 &&rhs)
{
  if (this != &rhs)
  {
    column1 = rhs.column1;
    column2 = rhs.column2;
    rhs.column1.SetZero();
    rhs.column2.SetZero();
  }
  return *this;
}

std::ostream& operator<<(std::ostream& output, const Matrix2& rhs)
{
  output << rhs.column1
    << rhs.column2;
  return output;
}

bool Matrix2::operator==(const Matrix2 &m1)
{
  return column1 == m1.column1 &&
    column2 == m1.column2;
}

bool Matrix2::operator!=(const Matrix2 &m1)
{
  return !(*this == m1);
}

bool operator==(const Matrix2 &m1, const Matrix2 &m2)
{
  return m1.column1 == m2.column1 &&
    m1.column2 == m2.column2;
}

bool operator!=(const Matrix2 &m1, const Matrix2 &m2)
{
  return !(m1 == m2);
}

float Matrix2::operator()(const int nColumn, const int nRow) const
{
  Vector2 tmp = (&column1)[nColumn];
  return tmp[nRow];
}

Matrix2 Matrix2::operator*(const float &scalar)
{
  return Matrix2(column1 * scalar, column2 * scalar);
}

Matrix2 Matrix2::operator+(const Matrix2 &rhs)
{
  return Matrix2(column1 + rhs.column1, column2 + rhs.column2);
}

Matrix2 Matrix2::Add(const Matrix2 &rhs)
{
  column1 += rhs.column1;
  column2 += rhs.column2;
  return *this;
}

//methods
void Matrix2::Adjoint()
{
  Cofactor();
  Transpose();
}

void Matrix2::Cofactor()
{
  Vector2 temp(column1);
  column1.SetVector(column2.GetY(), -column2.GetX());
  column2.SetVector(-temp.GetY(), temp.GetX());
}

Matrix2 Matrix2::Multiply(const Matrix2 &rhs)
{
  Vector2 row1(column1.GetX(), column2.GetX());
  Vector2 row2(column1.GetY(), column2.GetY());
  float x1 = row1.Dot(rhs.column1);
  float y1 = row2.Dot(rhs.column1);
  float x2 = row1.Dot(rhs.column2);
  float y2 = row2.Dot(rhs.column2);
  column1.SetVector(x1, y1);
  column2.SetVector(x2, y2);
  return *this;
}

void Matrix2::Transpose()
{
  Vector2 temp(column1);
  column1.SetVector(column1.GetX(), column2.GetX());
  column2.SetVector(temp.GetY(), column2.GetY());
}

void Matrix2::SetIdentity()
{
  column1.SetVector(1.0, 0.0);
  column2.SetVector(0.0, 1.0);
}

void Matrix2::SetZero()
{
  column1.SetZero();
  column2.SetZero();
}

Matrix2 Matrix2::GetInverse() const
{
  float determinate = GetDeterminate();

  if (determinate == 0)
  {
    return *this;
  }
  determinate = 1.0f / determinate;
  Matrix2 mat(column2.GetY(),
    -column1.GetY(), 
    -column2.GetX(),
    column1.GetX());

  return mat * determinate;
}

Vector2 Matrix2::Solve(const Vector2 &vec)
{
  float determinate = GetDeterminate();
  if (determinate == 0)
  {
    return Vector2(0, 0);
  }
  determinate = 1.0f / determinate;
  float x(column2.GetY() * vec.GetX() - column2.GetX() * vec.GetY());
  float y(column1.GetX() * vec.GetY() - column1.GetY() * vec.GetX());
  return Vector2(x, y) * determinate;
}

float Matrix2::GetDeterminate() const
{
  //TODO Clean this up.
  if (column1.IsZero() || column2.IsZero())
  {
    return 0;
  }
  float x0(column1.GetX());
  float y0(column1.GetY());
  float x1(column2.GetX());
  float y1(column2.GetY());
  return x0 * y1 - x1 * y0;
}

Vector2 operator*(const Matrix2 &mat, Vector2 &vec)
{
  return Vector2((mat.GetColumn1().GetX()) * (vec.GetX()) +
    (mat.GetColumn2().GetX()) * (vec.GetY()),
    (mat.GetColumn1().GetY()) * (vec.GetX()) +
    (mat.GetColumn2().GetY()) * (vec.GetY()));
}

Matrix2 operator*(const Matrix2 &mat1, const Matrix2 &matrix2)
{
  Matrix2 tmp(mat1);
  tmp.Multiply(matrix2);
  return tmp;
}

Matrix2 operator*(const float &scalar, const Matrix2 &mat1)
{
  Matrix2 mat(mat1);
  return mat * scalar;
}
