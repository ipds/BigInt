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
#include <algorithm>
#include <vector>
#include "BigInt.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  MAIN FUNCTION

Multiprecision BigInt::Multiply(Multiprecision x, Multiprecision y) const {
    uint_fast8_t carry = 0;
    Multiprecision fraction{};
    Multiprecision res{0};
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());
    for (unsigned int i = 0; i < x.size(); ++i) {
        for (auto &y_elem : y) {
            carry += (x[i] * y_elem);
            if (carry >= 10) {
                fraction.push_back(carry % uint_fast8_t(base));
                carry -= (carry % uint_fast8_t(base));
                carry /= uint_fast8_t(base);
            } else {
                fraction.push_back(carry);
                carry = 0;
            }
        }
        if (carry) {
            fraction.push_back(carry);
            carry = 0;
        }
        std::reverse(fraction.begin(), fraction.end());
        for (unsigned int j = 0; j < i; ++j) {
            fraction.push_back(0);
        }
        res = Add(res, fraction);
        fraction.clear();
    }
    return res;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  ONE ARGUMENT

void BigInt::Multiply(BigInt x) {
    Set(Multiply(GetVector(), x.GetVector()));
    Signed = (IsSigned() && !x.IsSigned()) || (x.IsSigned() && !IsSigned());
}

void BigInt::Multiply(Multiprecision x) {
    BigInt z(std::move(x));
    Multiply(z);
}

void BigInt::Multiply(std::string x) {
    BigInt z(std::move(x));
    Multiply(z);
}

void BigInt::Multiply(long long x) {
    BigInt z(x);
    Multiply(z);
}

BigInt BigInt::Multiply(BigInt x) const {
    BigInt z(GetVector());
    z.SetSign(IsSigned());
    z.Multiply(std::move(x));
    return z;
}
