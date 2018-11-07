//
// Created by Adam Szokalski on 31/10/2018.
//

#include "BigInt.h"
#include <cmath>

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  TO VECTOR

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

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  TO STRING

std::string BigInt::ToString(Multiprecision x) const {
    std::string ret = "";
    if(Signed){ ret += "-"; }
    for(unsigned int i = 0; i < x.size() / sizeof(uint_fast8_t); ++i){
        ret += std::to_string(int(x[i]));
    }
    return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  TO INT

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