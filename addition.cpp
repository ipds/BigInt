//
// Created by Adam Szokalski on 31/10/2018.
//

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

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