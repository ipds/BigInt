//
// Created by Adam Szokalski on 31/10/2018.
//

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Add(Multiprecision x, Multiprecision y) const {
    uint_fast8_t carry = 0;
    Multiprecision res{};

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for(unsigned int i = 0; i < std::max(x.size(), y.size()) || carry; ++i){
        if(i == x.size()) x.push_back(0);
        if(i == y.size()) y.push_back(0);

        carry += x[i] + y[i];

        if(carry >= base){
            res.push_back(carry - uint_fast8_t(base));
            carry = 1;
        } else{
            res.push_back(carry);
            carry = 0;
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  ONE ARGUMENT

void BigInt::Add(BigInt x){
    if(IsSigned()){
        BigInt z(GetVector());
        z.SetSign(false);
        x.Subtract(z);
        Set(x.GetVector());
        SetSign(x.IsSigned());
    } else if(x.IsSigned()){
        x.SetSign(false);
        Subtract(x);
    } else{
        Set(Add(GetVector(), x.GetVector()));
    }
}

void BigInt::Add(Multiprecision x){
    BigInt z(x);
    Add(z);
}

void BigInt::Add(std::string x){
    BigInt z(x);
    Add(z);
}

void BigInt::Add(long long x){
    BigInt z(x);
    Add(z);
}

BigInt BigInt::Add(BigInt x) const{
    BigInt z(GetVector());
    z.SetSign(IsSigned());
    z.Add(x);
    return z;
}