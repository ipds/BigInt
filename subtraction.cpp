//
// Created by Adam Szokalski on 31/10/2018.
//

#include <utility>

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Subtract(Multiprecision x, Multiprecision y) const{
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