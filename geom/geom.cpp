#include <iostream>
#include <limits>

#include "geom.hpp"


const double PI = acos(-1);
const double EPS = 2 * std::numeric_limits<double>::min();

std::ostream& operator<<(std::ostream& out, const Rdec2D& a);

std::ostream& operator<<(std::ostream& out, const Rpol2D& a);

// Dec coordinats

// Sum

Rdec2D& operator+=(Rdec2D& a, const Rdec2D& b) {
    
    a.x += b.x;
    a.y += b.y;
    return a;
}
Rdec2D operator+(Rdec2D a, const Rdec2D& b) {

    a += b;
    return a;
}

// Substraction

Rdec2D operator-(const Rdec2D& a) {
    return (Rdec2D(-a.x, -a.y));
}

Rdec2D& operator-=(Rdec2D& a, const Rdec2D& b) {

    a.x -= b.x;
    a.y -= b.y;
    return a;
}
Rdec2D operator-(Rdec2D a, const Rdec2D& b) {

    a -= b;
    return a;
}

// Multiplication on scalar

Rdec2D& operator*=(Rdec2D& a, const double& b) {

    a.x *= b;
    a.y *= b;
    return a;
}
Rdec2D operator*(const double& b, Rdec2D a) {

    a *= b;
    return a;
}
Rdec2D operator*(Rdec2D a, const double& b) {

    a *= b;
    return a;
}

// Devision on scalar

Rdec2D& operator/=(Rdec2D& a, const double& b) {

    a.x /= b;
    a.y /= b;
    return a;
}
Rdec2D& operator/(Rdec2D a, const double& b) {

    a /= b;
    return a;
}

// Logical operators

bool operator==(const Rdec2D& a, const Rdec2D& b) {
    return (std::abs(a.x - b.x < EPS) && std::abs(a.y - b.y < EPS));
}
bool operator!=(const Rdec2D& a, const Rdec2D& b) {
    return !((a.x - b.x < EPS) && (a.y - b.y < EPS));
}

// Dot product
double operator*(const Rdec2D& a, const Rdec2D& b) {
    return (a.x * b.x + a.y * b.y);
}
double Dot (const Rdec2D& a, const Rdec2D& b) {
    return (a.x * b.x + a.y * b.y);   
}

// Norm
double Norm(const Rdec2D& a) {
    return std::sqrt(a.x*a.x + a.y*a.y);
}

//Out
std::ostream& operator<<(std::ostream& out, const Rdec2D& a) {
    out << '{' << a.x << ' ' << a.y << '}';
    return out;
}

Rpol2D convertToPol(const Rdec2D& a) {

    return Rpol2D(Norm(a), acos(a.x / Norm(a)));
}


// Polar coordinats

Rdec2D convertToDec(const Rpol2D& a) {

    return Rdec2D(a.r*cos(a.phi), a.r*sin(a.phi));
}

// Multiplication on scalar

Rpol2D& operator*=(Rpol2D& a, const double& b) {

    a.r *= b;
    if (b < 0) {
        a.phi = (a.phi + PI) - 2*PI * (a.phi + PI > 2*PI);
    }
    return a;
}
Rpol2D operator*(const double& b, Rpol2D a) {

    a *= b;
    return a;
}
Rpol2D operator*(Rpol2D a, const double& b) {

    a *= b;
    return a;
}

// Devision on scalar

Rpol2D& operator/=(Rpol2D& a, const double& b) {

    a.r /= std::abs(b);
    if (b < 0) {
        a.phi = (a.phi + PI) - 2*PI * (a.phi + PI > 2*PI);
    }
    return a;
}
Rpol2D operator/(Rpol2D a, const double& b) {

    a /= b;
    return a;
}

// Function to summ

double atan2(double x, double y) {

    if (x > 0)
        return atan(x / y);
    else if (x < 0 && y > 0)
        return atan(x / y) + PI;
    else if (x < 0 && y < 0)
        return atan(x / y) - PI;
    else if (x == 0 && y > 0)
        return PI/2;
    else if (x == 0 && y < 0)
        return -PI/2;
    //else if (x == 0 && y == 0)
    //    throw std::runtime_error("Can't determine angel of dot");
    return -1;
}

// Sum

Rpol2D& operator+=(Rpol2D& a, const Rpol2D& b) {

    double r = std::sqrt(a.r*a.r + b.r*b.r + 2*a.r*b.r*cos(b.phi - a.phi));
    double phi = atan2(b.r*sin(b.phi - a.phi), a.r + b.r*cos(b.phi - a.phi));
    a = Rpol2D(r, phi);
    return a;
}
Rpol2D operator+(Rpol2D a, const Rpol2D& b) {

    a += b;
    return a;
}

// Substraction

Rpol2D operator-(const Rpol2D& a) {
    return Rpol2D(a.r, (a.phi + PI) - 2*PI * (a.phi + PI > 2*PI));
}

Rpol2D& operator-=(Rpol2D& a, const Rpol2D& b) {

    a += ((-1) * b);
    return a;
}
Rpol2D operator-(Rpol2D a, const Rpol2D& b) {

    a -= b;
    return a;
}

// Logical operators

bool operator==(const Rpol2D& a, const Rpol2D& b) {
    return (std::abs(a.r - b.r) < EPS && std::abs(a.phi - b.phi) < EPS);
}
bool operator!=(const Rpol2D& a, const Rpol2D& b) {
    return !(std::abs(a.r - b.r) < EPS && std::abs(a.phi - b.phi) < EPS);
}

// Dot product
double operator* (const Rpol2D& a, const Rpol2D& b) {
    return a.r * b.r * cos(std::abs(a.phi - b.phi));
}
double Dot (const Rpol2D& a, const Rpol2D& b) {
    return a.r * b.r * cos(std::abs(a.phi - b.phi));
}

//Norm
double Norm (const Rpol2D& a) {
    return a.r;
}

//Out
std::ostream& operator<<(std::ostream& out, const Rpol2D& a) {
    out << "r : " << a.r << ' ' << "phi : " << a.phi;
    return out;
}