//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <Matrix3.h>
//TODO Finish Methods.
//TODO REORG THIS FILE
//TODO Maybe add Subtraction of a Scalar
Matrix3::Matrix3() = default;

Matrix3::Matrix3(const Vector3& column1, const Vector3& column2, const Vector3& column3):
  column1(column1),
  column2(column2),
  column3(column3)
{}

Matrix3::Matrix3(const float x0, const float y0, const float z0,
  const float x1, const float y1, const float z1,
  const float x2, const float y2, const float z2):
  column1(x0, y0, z0),
  column2(x1, y1, z1),
  column3(x2, y2, z2)
{}

Matrix3::Matrix3(const Matrix3 &rhs) :
  column1(rhs.column1),
  column2(rhs.column2),
  column3(rhs.column3)
{}

Matrix3::Matrix3(Matrix3 &&rhs):
column1(),
column2(),
column3()
{
  column1 = rhs.column1;
  column2 = rhs.column2;
  column3 = rhs.column3;
  rhs.column1.SetZero();
  rhs.column2.SetZero();
  rhs.column3.SetZero();
}

Matrix3::~Matrix3() = default;

std::ostream& operator<<(std::ostream &output, const Matrix3 &rhs)
{
  output << rhs.column1
    << rhs.column2
    << rhs.column3;
  return output;
}

bool Matrix3::operator==(const Matrix3 &rhs)
{
  return column1 == rhs.column1 &&
    column2 == rhs.column2 &&
    column3 == rhs.column3;
}

bool operator==(const Matrix3 &m1, const Matrix3 &m2)
{
  return m1.column1 == m2.column1 &&
    m1.column2 == m2.column2 &&
    m1.column3 == m2.column3;
}

bool Matrix3::operator!=(const Matrix3 &rhs)
{
  return !(*this == rhs);
}

bool operator!=(const Matrix3 &m1, const Matrix3 &m2)
{
  return !(m1 == m2);
}

float Matrix3::operator()(const int nColumn, const int nRow) const
{
  Vector3 tmp = (&column1)[nColumn];
  return tmp[nRow];
}

Matrix3 Matrix3::operator*(const float &scalar) const
{
  return Matrix3(column1 * scalar, column2 * scalar, column3 * scalar);
}

Matrix3 Matrix3::operator+(const Matrix3 &rhs)
{
  return Matrix3(column1 + rhs.column1, column2 + rhs.column2, column3 + rhs.column3);
}

Matrix3& Matrix3::operator=(const Matrix3 &rhs)
{
  if (&rhs != this)
  {
    column1 = rhs.column1;
    column2 = rhs.column2;
    column3 = rhs.column3;
  }
  return *this;
}

Matrix3& Matrix3::operator=(Matrix3 &&rhs)
{
  if (&rhs != this)
  {
    column1 = rhs.column1;
    column2 = rhs.column2;
    column3 = rhs.column3;
    rhs.column1.SetZero();
    rhs.column2.SetZero();
    rhs.column3.SetZero();
  }
  return *this;
}

//methods
Matrix3 Matrix3::Minor()
{
  Matrix3 minor;
  float c1r1 = NegativeZero((column2.GetY() * column3.GetZ()) - (column3.GetY() * column2.GetZ()));
  float c1r2 = NegativeZero((column2.GetX() * column3.GetZ()) - (column3.GetX() * column2.GetZ()));
  float c1r3 = NegativeZero((column2.GetX() * column3.GetY()) - (column3.GetX() * column2.GetY()));
  float c2r1 = NegativeZero((column1.GetY() * column3.GetZ()) - (column3.GetY() * column1.GetZ()));
  float c2r2 = NegativeZero((column1.GetX() * column3.GetZ()) - (column3.GetX() * column1.GetZ()));
  float c2r3 = NegativeZero((column1.GetX() * column3.GetY()) - (column3.GetX() * column1.GetY()));
  float c3r1 = NegativeZero((column1.GetY() * column2.GetZ()) - (column2.GetY() * column1.GetZ()));
  float c3r2 = NegativeZero((column1.GetX() * column2.GetZ()) - (column2.GetX() * column1.GetZ()));
  float c3r3 = NegativeZero((column1.GetX() * column2.GetY()) - (column2.GetX() * column1.GetY()));
  minor.column1.SetVector(c1r1, c1r2, c1r3);
  minor.column2.SetVector(c2r1, c2r2, c2r3);
  minor.column3.SetVector(c3r1, c3r2, c3r3);
  return minor;
}

Matrix3& Matrix3::Add(const Matrix3 &rhs)
{
  column1 += rhs.column1;
  column2 += rhs.column2;
  column3 += rhs.column3;
  return *this;
}

void Matrix3::Adjoint()
{
  Cofactor();
  Transpose();
}

void Matrix3::Cofactor()
{
  Matrix3 mat = Minor();
  float c1r2 = mat.column1.GetY() * -1;
  float c2r1 = mat.column2.GetX() * -1;
  float c2r3 = mat.column2.GetZ() * -1;
  float c3r2 = mat.column3.GetY() * -1;
  mat.column1.SetY(c1r2);
  mat.column2.SetX(c2r1);
  mat.column2.SetZ(c2r3);
  mat.column3.SetY(c3r2);
  column1 = mat.column1;
  column2 = mat.column2;
  column3 = mat.column3;
}

Matrix3& Matrix3::Multiply(const Matrix3 &rhs)
{
  Vector3 r1(column1.GetX(), column2.GetX(), column3.GetX());
  Vector3 r2(column1.GetY(), column2.GetY(), column3.GetY());
  Vector3 r3(column1.GetZ(), column2.GetZ(), column3.GetZ());
  column1.SetVector(r1.Dot(rhs.column1), r2.Dot(rhs.column1), r3.Dot(rhs.column1));
  column2.SetVector(r1.Dot(rhs.column2), r2.Dot(rhs.column2), r3.Dot(rhs.column2));
  column3.SetVector(r1.Dot(rhs.column3), r2.Dot(rhs.column3), r3.Dot(rhs.column3));
  return *this;
}

Matrix3 Matrix3::Multiply(const Matrix3 &rhs) const
{
  Vector3 r1(column1.GetX(), column2.GetX(), column3.GetX());
  Vector3 r2(column1.GetY(), column2.GetY(), column3.GetY());
  Vector3 r3(column1.GetZ(), column2.GetZ(), column3.GetZ());
  Vector3 c1(r1.Dot(rhs.column1), r2.Dot(rhs.column1), r3.Dot(rhs.column1));
  Vector3 c2(r1.Dot(rhs.column2), r2.Dot(rhs.column2), r3.Dot(rhs.column2));
  Vector3 c3(r1.Dot(rhs.column3), r2.Dot(rhs.column3), r3.Dot(rhs.column3));
  return Matrix3(c1, c2, c3);
}

Vector3 Matrix3::MatrixVectorProduct(const Vector3 &v1) const
{
  Vector3 r1(column1.GetX(), column2.GetX(), column3.GetX());
  Vector3 r2(column1.GetY(), column2.GetY(), column3.GetY());
  Vector3 r3(column1.GetZ(), column2.GetZ(), column3.GetZ());

  return Vector3(r1.Dot(v1), r2.Dot(v1), r3.Dot(v1));
}

void Matrix3::Transpose()
{
  Vector3 temp1 = column1;
  Vector3 temp2 = column2;
  column1.SetVector(column1.GetX(), column2.GetX(), column3.GetX());
  column2.SetVector(temp1.GetY(), column2.GetY(), column3.GetY());
  column3.SetVector(temp1.GetZ(), temp2.GetZ(), column3.GetZ());
}

void Matrix3::SetIdentity()
{
  SetZero();
  column1.SetVector(1.0, 0, 0);
  column2.SetVector(0, 1.0, 0);
  column3.SetVector(0, 0, 1.0);
}

void Matrix3::SetZero()
{
  column1.SetZero();
  column2.SetZero();
  column3.SetZero();
}

//Get the inverse of  the Matrix
Matrix3 Matrix3::GetInverse() const
{
  float det = GetDeterminate();
  if (det != 0)
  {
    det = 1 / det;
  }
  Matrix3 mat(*this);
  mat.Adjoint();
  return mat * det;
}

//Solve for x in A * x = b.  where b is a column vector.
Vector3 Matrix3::Solve(const Vector3 &vec)
{
  Matrix3 m1 = GetInverse();
  return m1 * vec;
}

//Get determinate of this matrix
float Matrix3::GetDeterminate() const
{
  if (column1.IsZero() || column2.IsZero() || column3.IsZero())
  {
    return 0;
  }
  return (column1.GetX() * column2.GetY() *column3.GetZ()) +
    (column2.GetX() * column3.GetY() * column1.GetZ()) +
    (column3.GetX() * column1.GetY() * column2.GetZ()) -
    (column3.GetX() * column2.GetY() * column1.GetZ()) -
    (column2.GetX() * column1.GetY() * column3.GetZ()) -
    (column1.GetX() * column3.GetY() * column2.GetZ());
}

float Matrix3::NegativeZero(float x)
{
  if (x == -0)
    return 0;
  else
    return x;
}

//Multiply a Matrix times a vector.
Vector3 operator*(const Matrix3 &matrix, const Vector3 &vector)
{
  Vector3 answer = matrix.MatrixVectorProduct(vector);
  return answer;
}
//Multiply a Matrix times a Matrix.
Matrix3 operator*(const Matrix3 &matrix1, const Matrix3 &matrix2)
{
  //TODO * operatormatrix1.Multiply(matrix2)
   return Matrix3(matrix1.Multiply(matrix2));
}

Matrix3 operator*(const float &scalar, const Matrix3 &matrix1)
{
  Matrix3 m1 = matrix1 * scalar;
  return m1;
}