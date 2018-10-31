#include "BigInt.h"//
// Created by Adam Szokalski on 31/10/2018.
//
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>



int BigInt::CountDigits(long long n) const {
    return int(ceil(log10(n)));
}

long long BigInt::Sum(Multiprecision x) const{
    long long ret = 0;
    for (auto& i : x){ ret += i; }
    return ret;
}

Multiprecision  BigInt::ToVector(std::string x) const {
    Multiprecision ret{};
    for (unsigned int i = 0; i <  x.size(); ++i) {
    ret.push_back(uint_fast8_t(x[i] - '0'));
    }
    return ret;
}

Multiprecision  BigInt::ToVector(long long x) const{
    Multiprecision ret{};
    while (x > 0) {
        int digit = (int) (x % 10);
        ret.push_back(digit - 1);
        x /= 10;
    }
    return ret;
}

std::string BigInt::ToString(Multiprecision x) const {
    std::string ret = "";
    if(Signed){ ret += "-"; }
    for(unsigned int i = 0; i < x.size() / sizeof(uint_fast8_t); ++i){
        ret += std::to_string(int(x[i]));
    }
    return ret;
}

long long BigInt::ToInt(Multiprecision x) const {
    if(x.size()/ sizeof(uint_fast8_t) > CountDigits(LONG_LONG_MAX)){
        return 0;
    } else{
        long long ret = 0;
        int current;
        int size = x.size()/ sizeof(uint_fast8_t) - 1;
        for(unsigned int i = 0; i <= x.size()/ sizeof(uint_fast8_t) - 1; ++i){
            if(x[i] == 0) { ret *= pow(10, size - 1); }
            else if(x[i] == 1) { ret += pow(10, size - i); }
            else { ret += x[i] * pow(10, size - i); }
        }
        if(Signed){ ret *= -1; }
        return ret;
    }
}

Multiprecision BigInt::Add(Multiprecision x, Multiprecision y) const {
    unsigned long x_size = x.size();
    unsigned long y_size = y.size();
    unsigned long res_size{};
    uint_fast8_t curr = 0;
    Multiprecision res{};

    if(x_size>y_size){
        res_size = x_size;
        for(unsigned int i = 0; i < res_size - y_size; ++i){
            y.insert(y.begin(), uint_fast8_t(0));
        }
    } else{
        res_size = y_size;
        for(unsigned int j = 0; j < res_size - x_size; ++j){
            x.insert(x.begin(), uint_fast8_t(0));
        }
    }

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for(unsigned int k = 0; k < res_size; ++k){
        curr += x[k] + y[k];
        if(curr >= 10){
            res.push_back(curr - uint_fast8_t(10));
            curr = 1;
            if(k == res_size -1){
                res.push_back(curr);
            }
        } else{
            res.push_back(curr);
            curr = 0;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

Multiprecision BigInt::Substract(Multiprecision x, Multiprecision y) const{
    unsigned long x_size = x.size();
    unsigned long y_size = y.size();
    unsigned long res_size{};
    int_fast8_t curr = 0;
    Multiprecision res{};

    if(x_size>y_size){
        res_size = x_size;
        for(unsigned int i = 0; i < res_size - y_size; ++i){
            y.insert(y.begin(), uint_fast8_t(0));
        }
    } else{
        res_size = y_size;
        for(unsigned int j = 0; j < res_size - x_size; ++j){
            x.insert(x.begin(), uint_fast8_t(0));
        }
    }

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for(unsigned int k = 0; k < res_size; ++k){
        curr += x[k] - y[k];
        if(curr < 0){
            res.push_back(uint_fast8_t(curr) + uint_fast8_t(10));
            curr = -1;
        } else{
            res.push_back(uint_fast8_t(curr));
            curr = 0;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

BigInt::BigInt(){ Set(0); }

BigInt::BigInt(Multiprecision root){ Set(std::move(root)); }

BigInt::BigInt(std::string root){ Set(std::move(root)); }

BigInt::BigInt(long long root){ Set(root); }

std::string BigInt::GetString() const {
    return ToString(num);
}

long long BigInt::GetInt() const {
    return ToInt(num);
}

Multiprecision BigInt::GetVector() const {
    return num;
}

bool BigInt::IsSigned() const{
    return Signed;
}

void BigInt::Print() const {
    std::cout<<GetString()<<std::endl;
}

void BigInt::Set(Multiprecision root){
    num = root;
}

void BigInt::Set(std::string root){
    num.clear();
    num.reserve(root.size());
    Signed = (root[0] == '-');
    Set(ToVector(root));
}

void BigInt::Set(long long root){
    Set(std::to_string(root));

}

void BigInt::Extend(std::string root){
    for(unsigned int i = 0; i <root.size(); ++i){
        num.push_back(uint_fast8_t(root[i]));
    }
}

void BigInt::Add(Multiprecision x){
    Set(Add(num, x));
}

void BigInt::Add(std::string x){
    Set(Add(num, ToVector(x)));
}

void BigInt::Add(long long x){
    Add(ToVector(std::to_string(x)));
}

void BigInt::Add(BigInt x){
    Add(x.GetVector());
}

void BigInt::Substract(BigInt x){
    if(Compare(x) == 2){
        Set(Substract(x.GetVector(), GetVector()));
        Signed = true;
    } else{
        Set(Substract(GetVector(), x.GetVector()));
    }
}

void BigInt::Add(std::string x, std::string y){
    Multiprecision x_vector = ToVector(x);
    Multiprecision y_vector = ToVector(y);
    return Add(Add(x_vector, y_vector));
}
void BigInt::Add(long long x, long long y){
    Add(std::to_string(x), std::to_string(y));
}

void BigInt::Add(BigInt x, BigInt y){
    Add(x.GetVector(), y.GetVector());
}

BigInt BigInt::Substract(BigInt x) const{
    BigInt res(num);
    res.Substract(x);
    return res;
}

long long BigInt::Sum() const{
    return Sum(num);
}


int BigInt::Compare(BigInt x) const{
    if(IsSigned()){
        if(x.IsSigned()){
            if(GetVector().size() > x.GetVector().size()){
                return 2;
            } else if(GetVector().size() < x.GetVector().size()){
                return 1;
            } else{
                if(Sum() > x.Sum()){
                    return 2;
                } else if (Sum() > x.Sum()){
                    return 1;
                } else{
                    return 0;
                }
            }
        } else{
            return 2;
        }
    } else{
        if(x.IsSigned()){
            return 2;
        } else{
            if(GetVector().size() > x.GetVector().size()){
                return 1;
            } else if(GetVector().size() < x.GetVector().size()){
                return 2;
            } else{
                if(Sum() > x.Sum()){
                    return 1;
                } else if (Sum() > x.Sum()){
                    return 2;
                } else{
                    return 0;
                }
            }
        }
    }
}

bool BigInt::Equals(BigInt x) const{
    return (Signed == x.IsSigned() && Sum() == x.Sum());
}

bool BigInt::IsGreater(BigInt x) const{
    return (Compare(x) == 1);
}

bool BigInt::IsSmaller(BigInt x) const{
    return (Compare(x) == 2);
}

std::ostream &operator << (std::ostream &os, BigInt const &m) {
    return os << m.GetString();
}

std::istream & operator >> (std::istream &in,  BigInt &c)
{
    std::string arg;
    in >> arg;
    c.Set(arg);
    return in;
}

BigInt operator+(const BigInt &x, const BigInt &y)
{
    return BigInt(x.Add(x.GetVector(), y.GetVector()));
}

BigInt operator-(const BigInt &x, const BigInt &y)
{
    return x.Substract(y);
}