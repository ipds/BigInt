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


#include <utility>

#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Subtract(Multiprecision x, Multiprecision y) const{
    int_fast8_t carry = 0;
    Multiprecision res{};

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for(unsigned int i = 0; i < std::max(x.size(), y.size()); ++i){
        if(i == x.size()) x.push_back(0);
        if(i == y.size()) y.push_back(0);

        carry += x[i] - y[i];

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