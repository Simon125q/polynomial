#include <iostream>
#include <map>
#include <math.h>
#include "Poly.h"

using namespace std;

#define ERROR 1

Poly::Poly(double val)
{
    coefficients.clear();
    coefficients[0] = val;
}

double &Poly::operator[](int coef_num)
{
    return coefficients[coef_num];
}

double Poly::operator()(double x) const
{
    map<int, double>::const_iterator it = coefficients.begin();
    double result = 0;

    while (it != coefficients.end())
    {
        result = result + pow(x, it->first) * it->second;
        ++it;
    }

    return result;
}

Poly Poly::operator-() const
{
    map<int, double>::const_iterator it = coefficients.begin();
    Poly result;

    while (it != coefficients.end())
    {
        result.coefficients[it->first] = it->second * (-1);
        ++it;
    }

    return result;
}

Poly Poly::operator+(const Poly &other) const
{
    map<int, double>::const_iterator it = coefficients.begin();
    map<int, double>::const_iterator other_it = other.coefficients.begin();
    Poly result;

    while (it != coefficients.end())
    {
        result.coefficients[it->first] = it->second;
        ++it;
    }

    while (other_it != other.coefficients.end())
    {
        result.coefficients[other_it->first] = result.coefficients[other_it->first] + other_it->second;
        ++other_it;
    }

    return result;
}

Poly Poly::operator-(const Poly &other) const
{
    map<int, double>::const_iterator it = coefficients.begin();
    map<int, double>::const_iterator other_it = other.coefficients.begin();
    Poly result;

    while (it != coefficients.end())
    {
        result.coefficients[it->first] = it->second;
        ++it;
    }

    while (other_it != other.coefficients.end())
    {
        result.coefficients[other_it->first] = result.coefficients[other_it->first] - other_it->second;
        ++other_it;
    }

    return result;
}

Poly Poly::operator*(const Poly &other) const
{
    map<int, double>::const_iterator it = coefficients.begin();
    
    Poly result;
    while (it != coefficients.end())
    {
        map<int, double>::const_iterator other_it = other.coefficients.begin();
        while (other_it != other.coefficients.end())
        {
            result.coefficients[(it->first + other_it->first)] += it->second * other_it->second;
            ++other_it;
        }
        ++it;
    }
    
    return result;
}

Poly &Poly::operator=(const Poly &other)
{
    map<int, double>::const_iterator other_it = other.coefficients.begin();

    coefficients.clear();

    while (other_it != other.coefficients.end())
    {
        coefficients[other_it->first] = other_it->second;
        ++other_it;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Poly &other)
{
    map<int, double>::const_iterator it = other.coefficients.end();
    it--;
    if (it->second != 0)
    {
        if (it->first != 0)
            os << it->second << "x^" << it->first;
        else
            os << it->second;
    }

    while (it != other.coefficients.begin())
    {
        it--;
        if (it->second != 0)
        {
            if (it->second > 0)
                os << " + ";
            else if (it->second < 0)
                os << " - ";
            if (it->first != 0)
                os << abs(it->second) << "x^" << it->first;
            else
                os << abs(it->second);
        }
    }

    return os;
}

Poly operator+(double num, const Poly &obj)
{
    Poly result = obj;
    result.coefficients[0] += num;
    return result;
}

Poly operator-(double num, const Poly &obj)
{
    Poly result = -obj;
    result.coefficients[0] += num;
    return result;
}

Poly operator*(double num, const Poly &obj)
{
    Poly multiplier(num);
    Poly result = multiplier * obj;
    return result;
}

