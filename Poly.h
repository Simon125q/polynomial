#pragma once
#include <map>
#include <ostream>

class Poly
{
    std::map<int, double> coefficients;
public:
    
    Poly(double val = 0);
    double & operator [](int coef_num);
    double operator()(double x) const;
    Poly operator-() const;
    Poly operator+(const Poly &other) const;
    Poly operator-(const Poly &other) const;
    Poly operator*(const Poly &other) const;
    Poly &operator=(const Poly &other);
    friend std::ostream &operator<<(std::ostream &os, const Poly &other);
    friend Poly operator+(double num, const Poly &obj);
    friend Poly operator-(double num, const Poly &obj);
    friend Poly operator*(double num, const Poly &obj);
};
    
