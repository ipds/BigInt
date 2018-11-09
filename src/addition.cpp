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