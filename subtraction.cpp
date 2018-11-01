//
// Created by Adam Szokalski on 31/10/2018.
//

#include <utility>

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Subtract(Multiprecision x, Multiprecision y) const{
    int_fast8_t carry = 0;
    Multiprecision res{};

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for(unsigned int k = 0; k < std::max(x.size(), y.size()); ++k){
        carry += x[k] - y[k];
        if(carry < 0){
            res.push_back(uint_fast8_t(carry) + uint_fast8_t(base));
            carry = -1;
        } else{
            res.push_back(uint_fast8_t(carry));
            carry = 0;
        }
    }

    while (res.size() > 1 && res.back() == 0){
        res.pop_back();
    }

    reverse(res.begin(), res.end());

    return res;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  ONE ARGUMENT

void BigInt::Subtract(BigInt x) {
    if(IsSigned()){
        if(x.IsSigned()){
            if(Compare(x) == 2){
                Set(Subtract(GetVector(), x.GetVector()));
                Signed = true;
            } else{
                Set(Subtract(x.GetVector(), GetVector()));
                Signed = false;
            }
        } else {
            Set(Add(GetVector(), x.GetVector()));
            Signed = true;
        }
    } else{
        if(x.IsSigned()){
            Set(Add(GetVector(), x.GetVector()));
            Signed = false;
        } else{
            if(Compare(x) == 2){
                Set(Subtract(x.GetVector(), GetVector()));
                Signed = true;
            } else{
                Set(Subtract(GetVector(), x.GetVector()));
                Signed = false;
            }
        }
    }
}

void BigInt::Subtract(Multiprecision x){
    BigInt z(std::move(x));
    Subtract(z);
}

void BigInt::Subtract(std::string x){
    BigInt z(std::move(x));
    Subtract(z);
}

void BigInt::Subtract(long long x){
    BigInt z(x);
    Subtract(z);
}

BigInt BigInt::Subtract(BigInt x) const{
    BigInt res(num);
    res.SetSign(IsSigned());
    res.Subtract(std::move(x));
    return res;
}