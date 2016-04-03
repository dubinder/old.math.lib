//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// Dylan Binder
// Copyright 2015
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <Matrix4.h>

Matrix4::Matrix4(){}

Matrix4::Matrix4(const Vector3& column1, const Vector3& column2, const Vector3& column3, const Vector3& column4):
m_column1(column1),
m_column2(column2),
m_column3(column3),
m_column4(column4)
{}

Matrix4::Matrix4(const Vector4& column1, const Vector4& column2, const Vector4& column3, const Vector4& column4):
m_column1(column1),
m_column2(column2),
m_column3(column3),
m_column4(column4)
{}


Matrix4::Matrix4(const float x0, const float y0, const float z0, const float w0,
  const float x1, const float y1, const float z1, const float w1,
  const float x2, const float y2, const float z2, const float w2,
  const float x3, const float y3, const float z3, const float w3):
  m_column1(x0, y0, z0, w0),
  m_column2(x1, y1, z1, w1),
  m_column3(x2, y2, z2, w2),
  m_column4(x3, y3, z3, w3)
{}

    //Matrix4(const Matrix4 &rhs);
    //Matrix4(Matrix4 &&rhs);

Matrix4::~Matrix4(){}

std::ostream& operator<<(std::ostream &output, const Matrix4 &rhs)
{
  output << rhs.m_column1 
    << rhs.m_column2 
    << rhs.m_column3 
    << rhs.m_column4
    << std::endl;
    return output;
}

Matrix4& Matrix4::operator=(const Matrix4 &rhs)
{
  if (this != &rhs)
  {
    m_column1 = rhs.m_column1;
    m_column2 = rhs.m_column2;
    m_column3 = rhs.m_column3;
    m_column4 = rhs.m_column4;
  }
  return *this;
}

Matrix4& Matrix4::operator=(Matrix4 &&rhs)
{
  if (this != &rhs)
  {
    m_column1 = std::move(rhs.m_column1);
    m_column2 = std::move(rhs.m_column2);
    m_column3 = std::move(rhs.m_column3);
    m_column4 = std::move(rhs.m_column4);
  }
  return *this;
}

bool Matrix4::operator==(const Matrix4 &m1)
{
  return m_column1 == m1.m_column1 &&
    m_column2 == m1.m_column2 &&
    m_column3 == m1.m_column3 &&
    m_column4 == m1.m_column4;
}

    //friend bool operator==(const Matrix4 &m1, const Matrix4 &m2);
    //bool operator!=(const Matrix4 &m1);
    //friend bool operator!=(const Matrix4 &m1, const Matrix4 &m2);
    //float operator()(const int nColumn, const int nRow) const;
    //Matrix4 operator*(const float &scalar) const;
    //Matrix4 operator+(const Matrix4 &rhs);

    ////methods
    //Matrix4 Minor();
    //Matrix4& Add(const Matrix4 &rhs);
    //void Adjoint();
    //void Cofactor();
Matrix4& Matrix4::Multiply(const Matrix4 &rhs)
{
  Vector4 r1(m_column1.m_x, m_column2.m_x, m_column3.m_x, m_column4.m_x);
  Vector4 r2(m_column1.m_y, m_column2.m_y, m_column3.m_y, m_column4.m_y);
  Vector4 r3(m_column1.m_z, m_column2.m_z, m_column3.m_z, m_column4.m_z);
  Vector4 r4(m_column1.m_w, m_column2.m_w, m_column3.m_w, m_column4.m_w);
  m_column1.m_x = r1.Dot(rhs.m_column1);
  m_column2.m_x = r1.Dot(rhs.m_column2);
  m_column3.m_x = r1.Dot(rhs.m_column3);
  m_column4.m_x = r1.Dot(rhs.m_column4);
  m_column1.m_y = r2.Dot(rhs.m_column1);
  m_column2.m_y = r2.Dot(rhs.m_column2);
  m_column3.m_y = r2.Dot(rhs.m_column3);
  m_column4.m_y = r2.Dot(rhs.m_column4);
  m_column1.m_z = r3.Dot(rhs.m_column1);
  m_column2.m_z = r3.Dot(rhs.m_column2);
  m_column3.m_z = r3.Dot(rhs.m_column3);
  m_column4.m_z = r3.Dot(rhs.m_column4);
  m_column1.m_w = r4.Dot(rhs.m_column1);
  m_column2.m_w = r4.Dot(rhs.m_column2);
  m_column3.m_w = r4.Dot(rhs.m_column3);
  m_column4.m_w = r4.Dot(rhs.m_column4);
  return *this;
}
    //Matrix4 Multiply(const Matrix4 &rhs) const;
    //Vector4 MatrixVectorProduct(const Vector3 &v1) const;
    //void Transpose();

void Matrix4::SetIdentity()
{
  m_column1 = Vector4(1, 0, 0, 0);
  m_column2 = Vector4(0, 1, 0, 0);
  m_column3 = Vector4(0, 0, 1, 0);
  m_column4 = Vector4(0, 0, 0, 1);
}

void Matrix4::SetZero()
{
  m_column1 = Vector4();
  m_column2 = Vector4();
  m_column3 = Vector4();
  m_column4 = Vector4();
}
    ////Get the inverse of  the Matrix
    //Matrix4 GetInverse() const;
    ////Solve for x in A * x = b.  where b is a column vector.
    //Vector3 Solve(const Vector3 &vec);
    ////Get determinate of this matrix
float Matrix4::GetDeterminate() const
{
  if (IsColumnZero() || ColumnsAreEqual() || RowsAreEqual())
  {
    return 0;
  }
  return
  m_column1.m_x * (m_column2.m_y * (m_column3.m_z * m_column4.m_w - m_column3.m_w * m_column4.m_z) - 
                   m_column2.m_z * (m_column3.m_y * m_column4.m_w - m_column3.m_w * m_column4.m_y) + 
                   m_column2.m_w * (m_column3.m_y * m_column4.m_z - m_column3.m_z * m_column4.m_y)) -
  m_column1.m_y * (m_column2.m_x * (m_column3.m_z * m_column4.m_w - m_column3.m_w * m_column4.m_z) -
                   m_column2.m_z * (m_column3.m_x * m_column4.m_w - m_column3.m_w * m_column4.m_x) +
                   m_column2.m_w * (m_column3.m_x * m_column4.m_z - m_column3.m_z * m_column4.m_x)) +
  m_column1.m_z * (m_column2.m_x * (m_column3.m_y * m_column4.m_w - m_column3.m_w * m_column4.m_y) -
                   m_column2.m_y * (m_column3.m_x * m_column4.m_w - m_column3.m_w * m_column4.m_x) +
                   m_column2.m_w * (m_column3.m_x * m_column4.m_y - m_column3.m_y * m_column4.m_x)) -
  m_column1.m_w * (m_column2.m_x * (m_column3.m_y * m_column4.m_z - m_column3.m_z * m_column4.m_y) -
                   m_column2.m_y * (m_column3.m_x * m_column4.m_z - m_column3.m_z * m_column4.m_x) +
                   m_column2.m_z * (m_column3.m_x * m_column4.m_y - m_column3.m_y * m_column4.m_x));
}

bool Matrix4::ColumnsAreEqual() const
{
  return m_column1 == m_column2 || m_column1 == m_column3 ||
    m_column1 == m_column4 || m_column2 == m_column3 ||
    m_column2 == m_column4 || m_column3 == m_column4;
}

//Returns true if any of the rows are the same
bool Matrix4::RowsAreEqual() const
{
  Vector4 r1(m_column1.m_x, m_column2.m_x, m_column3.m_x, m_column4.m_x);
  Vector4 r2(m_column1.m_y, m_column2.m_y, m_column3.m_y, m_column4.m_y);
  Vector4 r3(m_column1.m_z, m_column2.m_z, m_column3.m_z, m_column4.m_z);
  Vector4 r4(m_column1.m_w, m_column2.m_w, m_column3.m_w, m_column4.m_w);
  return r1 == r2 || r1 == r3 || r1 == r4 ||
    r2 == r3 || r2 == r4 ||
    r3 == r4;
}

bool Matrix4::IsColumnZero() const
{
  return m_column1.IsZero() || m_column2.IsZero() || m_column3.IsZero() || m_column4.IsZero();
}
    ////Get Column "1" of a matrix
    //Vector4 GetColumn1()const { return m_column1; }
    ////Get Column "2" of a matrix
    //Vector4 GetColumn2()const { return m_column2; }
    ////Get Column "3" of a matrix
    //Vector4 GetColumn3()const { return m_column3; }
    ////Get Column "4" of a matrix
    //Vector4 GetColumn4()const { return m_column4; }

    //float NegativeZero(float x);

