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
                } else if (Sum() < x.Sum()){
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