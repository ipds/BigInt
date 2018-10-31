//
// Created by Adam Szokalski on 31/10/2018.
//

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  I/O

std::ostream &operator << (std::ostream &os, BigInt const &m) {
    return os << m.GetString();
}

std::istream & operator >> (std::istream &in,  BigInt &c) {
    std::string arg;
    in >> arg;
    c.Set(arg);
    return in;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  ADDITION

BigInt operator+(const BigInt &x, const BigInt &y) {
    return BigInt(x.Add(x.GetVector(), y.GetVector()));
}

BigInt operator+(const long long &x, const BigInt &y) {
    BigInt z(x);
    return BigInt(z.Add(z.GetVector(), y.GetVector()));
}

BigInt operator+(const BigInt &x, const long long &y) {
    BigInt z(y);
    return BigInt(x.Add(x.GetVector(), z.GetVector()));
}

BigInt operator+(const std::string &x, const BigInt &y) {
    BigInt z(x);
    return BigInt(z.Add(z.GetVector(), y.GetVector()));
}

BigInt operator+(const BigInt &x, const std::string &y)
{
    BigInt z(y);
    return BigInt(x.Add(x.GetVector(), z.GetVector()));
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  SUBSTRACTION

BigInt operator-(const BigInt &x, const BigInt &y) {
    return x.Substract(y);
}

