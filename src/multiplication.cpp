//
// Created by Adam Szokalski on 01/11/2018.
//

#include <utility>

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Multiply(Multiprecision x, Multiprecision y) const {
    uint_fast8_t carry = 0;
    Multiprecision fraction{};
    Multiprecision res{0};
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for(unsigned int i = 0; i < x.size(); ++i)
    {
        for (auto &y_elem : y)
        {
            carry += (x[i] * y_elem);
            if(carry >= 10){
                fraction.push_back(carry % uint_fast8_t (base));
                carry -= (carry % uint_fast8_t (base));
                carry /= uint_fast8_t (base);
            } else {
                fraction.push_back(carry);
                carry = 0;
            }
        }
        if(carry){ fraction.push_back(carry); carry = 0; }
        reverse(fraction.begin(), fraction.end());
        for(unsigned int j = 0; j < i; ++j){
            fraction.push_back(0);
        }
        res = Add(res, fraction);
        fraction.clear();
    }
    return res;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  ONE ARGUMENT

void BigInt::Multiply(BigInt x){
    Set(Multiply(GetVector(), x.GetVector()));
    if(IsSigned() && !x.IsSigned() || !IsSigned() && x.IsSigned()){
        Signed = true;
    } else{
        Signed = false;
    }
}

void BigInt::Multiply(Multiprecision x){
    BigInt z(std::move(x));
    Multiply(z);
}

void BigInt::Multiply(std::string x){
    BigInt z(std::move(x));
    Multiply(z);
}

void BigInt::Multiply(long long x){
    BigInt z(x);
    Multiply(z);
}

BigInt BigInt::Multiply(BigInt x) const{
    BigInt z(GetVector());
    z.SetSign(IsSigned());
    z.Multiply(std::move(x));
    return z;
}
