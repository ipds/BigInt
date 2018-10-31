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

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  TWO ARGUMENT

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