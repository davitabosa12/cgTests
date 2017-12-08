#ifndef VEC2_H
#define VEC2_H
#include<cmath>
#include<string>
#include<sstream>
#include"vec3.h"

class Vec2
{
    public:
        static const Vec2 VEC2_ZERO;
        static const Vec2 VEC2_ONES;
        static const Vec2 VEC2_UP;
        static const Vec2 VEC2_DOWN;
        static const Vec2 VEC2_LEFT;
        static const Vec2 VEC2_RIGHT;
    private:
        double x;
        double y;
        double mag;
    public:
        Vec2();
        Vec2(double x, double y);
        virtual ~Vec2();
        Vec2(const Vec2& other);
        Vec2& operator=(const Vec2& other);
        double getX() const;
        void setX(double val);
        double getY() const;
        void setY(double val);
        double getMag() const;
        void setMag(double val);

        //Métodos estaticos
        static Vec2 add(Vec2 a, Vec2 b);
        static Vec2 subtr(Vec2 a, Vec2 b);
        static Vec2 mult(Vec2 a, double s);
        static Vec2 divide(Vec2 a, double s);
        static double dot(Vec2 a, Vec2 b);
        static double scross(Vec2 a, Vec2 b);
        static Vec3 cross(Vec2 a, Vec2 b);
        static Vec2 normalize(Vec2 a);
        static Vec2 projection(Vec2 a, Vec2 b);





};


//Sobrecarga de operadores
        static Vec2 operator+(Vec2 a, Vec2 b);
        static Vec2 operator-(Vec2 a, Vec2 b);
        static Vec2 operator*(Vec2 a, double s);
        static Vec2 operator/(Vec2 a, double s);
        static bool operator==(Vec2 a, Vec2 b);
        static Vec2 operator-(Vec2 a);
#endif // VEC2_H
