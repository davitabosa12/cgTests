#include "vec2.h"

const Vec2 Vec2::VEC2_ZERO = Vec2(0,0);
const Vec2 Vec2::VEC2_ONES = Vec2(1,1);
const Vec2 Vec2::VEC2_UP = Vec2(0,1);
const Vec2 Vec2::VEC2_DOWN = Vec2(0,-1);
const Vec2 Vec2::VEC2_LEFT = Vec2(-1,0);
const Vec2 Vec2::VEC2_RIGHT = Vec2(1,0);

Vec2::Vec2()
{
    x = 1;
    y = 0;
    mag = 1;
}

Vec2::Vec2(double x, double y)
{
    this->x = x;
    this->y = y;
    this->mag = sqrt(x*x + y*y);
}

Vec2::~Vec2()
{
    //dtor
}

Vec2::Vec2(const Vec2& other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->mag = other.getMag();
}

//Getters e Setters
double Vec2::getX() const
{
    return x;
}
void Vec2::setX(double val)
{
    x = val;
}
double Vec2::getY() const
{
    return y;
}
void Vec2::setY(double val)
{
    y = val;
}
double Vec2::getMag() const
{
    return mag;
}
void Vec2::setMag(double val)
{
    mag = val;
}

Vec2& Vec2::operator=(const Vec2& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Vec2 Vec2::add(Vec2 a, Vec2 b)
{
    return Vec2(a.getX() + b.getX(), a.getY() + b.getY());
}

Vec2 Vec2::subtr(Vec2 a, Vec2 b)
{
    return Vec2(a.getX() - b.getX(), a.getY() - b.getY());
}

Vec2 Vec2::mult(Vec2 a, double s)
{
    return Vec2(s * a.getX(), s * a.getY());
}

Vec2 Vec2::divide(Vec2 a, double s)
{
    if(s == 0)
        throw 111;
    else
        return Vec2(a.getX() / s, a.getY() / s);
}

Vec2 Vec2::normalize(Vec2 a)
{
    return Vec2(a.getX() / a.getMag(), a.getY() / a.getMag());
}

double Vec2::dot(Vec2 a, Vec2 b)
{
    return a.getX() * b.getX() + a.getY() * b.getY();
}

double Vec2::scross(Vec2 a, Vec2 b)
{
    return a.getX() * b.getY() - a.getY() * b.getX();
}

Vec3 Vec2::cross(Vec2 a, Vec2 b)
{
    return Vec3(0,0,a.getX() * b.getY() - a.getY() * b.getX());
}

/** @brief Operador inverter
  *
  * Inverte os valores de um vetor
  */
Vec2 operator-(Vec2 a)
{
    return Vec2(-a.getX(), -a.getY());
}

/** @brief Operador igualdade
  *
  * retorna true caso os dois vetores forem iguais
  */
bool operator==(Vec2 a, Vec2 b)
{
    return a.getX() == b.getX() && a.getY() == b.getY();
}

/** @brief Operador divisao por um escalar
  *
  * Divide o vetor a pelo escalar s, sendo s != 0
  */
Vec2 operator/(Vec2 a, double s)
{
    if(s == 0 )
        throw 111;
    return Vec2(a.getX() / s, a.getY() / s);
}

/** @brief Operador multiplicacao por um escalar
  *
  * Multiplica o vetor a pelo escalar s
  */
Vec2 operator*(Vec2 a, double s)
{
    return Vec2(a.getX() * s, a.getY() * s);
}

/** @brief Operador Subtracao
  *
  * Subtrai os vetores a e b
  */
Vec2 operator-(Vec2 a, Vec2 b)
{
    return Vec2(a.getX() - b.getX(), a.getY() - b.getY());
}

/** @brief (one liner)
  *
  * Soma os vetores a e b
  */
Vec2 operator+(Vec2 a, Vec2 b)
{
    return Vec2(a.getX() + b.getX(), a.getY() + b.getY());
}
