//BigInt is a simple arbitrary-precision c++ library created for Interplanetary Database System (IPDS) project and forming part of it.

//Copyright (C) 2018  Adam Szokalski and other authors < see https://ipds.network/authors or https://ipds.team >. All rights reserved.
//Using BigInt for commercial purposes requires an acknowledgment.

//https://ipds.network/bigint and https://github.com/ipds/BigInt
//Contact: contact@ipds.team or aszokalski@ipds.team

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Affero General Public License as published
//by the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Affero General Public License for more details.

//You should have received a copy of the GNU Affero General Public License
//along with this program.  If not, see <https://www.gnu.org/licenses/>.


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
//  LOGIC

bool operator==(const BigInt &x, const BigInt &y) {
    return x.Equals(y);
}

bool operator<(const BigInt &x, const BigInt &y) {
    return x.Compare(y) == 2;
}

bool operator>(const BigInt &x, const BigInt &y) {
    return x.Compare(y) == 1;
}

bool operator<=(const BigInt &x, const BigInt &y) {
    return (x < y || x == y);
}

bool operator>=(const BigInt &x, const BigInt &y) {
    return (x > y || x == y);
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

BigInt operator-(const long long &x, const BigInt &y) {
    const BigInt z(x);
    return z.Subtract(y);
}

BigInt operator-(const BigInt &x, const long long &y) {
    const BigInt z(y);
    return x.Subtract(z);
}

BigInt operator-(const std::string &x, const BigInt &y) {
    const BigInt z(x);
    return z.Subtract(y);
}

BigInt operator-(const BigInt &x, const std::string &y)
{
    const BigInt z(y);
    return x.Subtract(z);
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MULTIPLICATION

BigInt operator*(const BigInt &x, const BigInt &y) {
    return x.Multiply(y);
}

BigInt operator*(const long long &x, const BigInt &y) {
    const BigInt z(x);
    return z.Multiply(y);
}

BigInt operator*(const BigInt &x, const long long &y) {
    const BigInt z(y);
    return x.Multiply(z);
}

BigInt operator*(const std::string &x, const BigInt &y) {
    const BigInt z(x);
    return z.Multiply(y);
}

BigInt operator*(const BigInt &x, const std::string &y)
{
    const BigInt z(y);
    return x.Multiply(z);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  SHORT DIVISION

BigInt operator/(const BigInt &x, const uint_fast8_t &y) {
    BigInt z(x.GetString());
    z.Divide(y);
    return z;
}