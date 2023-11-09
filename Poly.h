#pragma once
#include <map>
#include <ostream>

class Poly
{
public:
    std::map<int, double> coefficients;
    
    Poly(double val = 0);
    double & operator [](int coef_num);
    double operator()(double x) const;
    Poly operator-() const;
    Poly operator+(const Poly &other) const;
    Poly operator-(const Poly &other) const;
    Poly operator*(const Poly &other) const;
    Poly &operator=(const Poly &other);
};
    
std::ostream &operator<<(std::ostream &os, const Poly &other);
Poly operator+(double num, const Poly &obj);
Poly operator-(double num, const Poly &obj);
Poly operator*(double num, const Poly &obj);