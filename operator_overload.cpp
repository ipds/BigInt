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
    return x.Add(y);
}

BigInt operator+(const long long &x, const BigInt &y) {
    const BigInt z(x);
    return z.Add(y);
}

BigInt operator+(const BigInt &x, const long long &y) {
    const BigInt z(y);
    return x.Add(z);
}

BigInt operator+(const std::string &x, const BigInt &y) {
    const BigInt z(x);
    return z.Add(y);
}

BigInt operator+(const BigInt &x, const std::string &y)
{
    const BigInt z(y);
    return x.Add(z);
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  SUBSTRACTION

BigInt operator-(const BigInt &x, const BigInt &y) {
    return x.Subtract(y);
}

