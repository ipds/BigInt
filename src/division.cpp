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
//  MAIN FUNCTION - SHORT DIVISION

Multiprecision BigInt::Divide(Multiprecision x, uint_fast8_t y) const{
    Multiprecision res{};
    uint_fast8_t  remainder = x[0];

    for (int i = 0; i < x.size(); ++i) {
        res.push_back(remainder / y);
        uint_fast8_t wholeNum = res[i] * y;
        remainder -= wholeNum;
        remainder *= 10;
        if(i < x.size() - 1) remainder +=  x[i + 1];
    }

    if(res.front() == 0){
        reverse(res.begin(), res.end());
        while (res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
    }

    return res;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION - LONG DIVISION

Multiprecision BigInt::Divide(Multiprecision n, Multiprecision d) const {
    BigInt numerator(n);
    BigInt denominator(d);

    unsigned long magnitude = d.size() - 1ul;
    uint_fast8_t quickDivisor = d[0];
    BigInt quotient = numerator / quickDivisor;
    BigInt remainder = denominator + 1;

    while (remainder.Abs() >= denominator) {
        remainder = numerator - (quotient * denominator);
        BigInt newQuotient = quotient + (remainder / quickDivisor);
        quotient = (quotient + newQuotient) / 2;
    }
    remainder = numerator - (quotient * denominator);

    if (remainder < BigInt(0)) {
        quotient = quotient - 1;
        remainder = remainder + denominator;
    }

    return quotient.GetVector();

}


void BigInt::Divide(uint_fast8_t x) {
    Set(Divide(GetVector(), x));
}

void BigInt::Divide(Multiprecision x) {
    BigInt z(GetVector());
    z.SetSign(IsSigned());
    Divide(z);
}

void BigInt::Divide(BigInt x) {
    Set(Divide(GetVector(), x.GetVector()));
    Signed = (IsSigned() && !x.IsSigned()) || (x.IsSigned() && !IsSigned());
}