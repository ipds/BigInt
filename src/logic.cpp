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
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>

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