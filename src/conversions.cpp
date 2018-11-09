//BigInt is a simple arbitrary-precision c++ library created for Interplanetary Database System (IPDS) project and forming part of it.

//Copyright (C) 2018  Adam Szokalski and other authors < see https://ipds.network/authors or https://ipds.team >. All rights reserved.
//Using BigInt for commercial purposes requires an acknowledgment.

//https://ipds.network/bigint and https://github.com/ipds/BigInt
//Contact: contact@ipds.team or aszokalski@ipds.team

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Affero General Public License as published
//by the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Affero General Public License for more details.

//You should have received a copy of the GNU Affero General Public License
//along with this program.  If not, see <https://www.gnu.org/licenses/>.


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