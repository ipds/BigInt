//
// Created by Adam Szokalski on 31/10/2018.
//

#include "BigInt.h"
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

long long BigInt::Sum() const{
    return Sum(num);
}

int BigInt::Compare(BigInt x) const{
    if(Equals(x)){
        return 0;
    } else if(GetVector().size() == x.GetVector().size()){
        Multiprecision tv = GetVector();
        Multiprecision xv = x.GetVector();
        for (unsigned int i = 0; i < tv.size(); ++i) {
            if(tv[i] > xv[i]){
                return 1;
            } else if (tv[i] < xv[i]){
                return 2;
            }
        }
    } else{
        return (GetVector().size() * (IsSigned() ? -1 : 1) < x.GetVector().size() * (x.IsSigned() ? -1 : 1)) + 1;
    }
}

bool BigInt::Equals(BigInt x) const{
    return (Signed == x.IsSigned() && GetVector() == x.GetVector());
}

bool BigInt::IsGreater(BigInt x) const{
    return (Compare(x) == 1);
}

bool BigInt::IsSmaller(BigInt x) const{
    return (Compare(x) == 2);
}