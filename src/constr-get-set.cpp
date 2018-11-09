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
//  CONSTRUCTORS

BigInt::BigInt(){ Set(0); }

BigInt::BigInt(Multiprecision root){ Set(std::move(root)); }

BigInt::BigInt(std::string root){ Set(std::move(root)); }

BigInt::BigInt(long long root){ Set(root); }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  GET

std::string BigInt::GetString() const {
    return ToString(num);
}

long long BigInt::GetInt() const {
    return ToInt(num);
}

Multiprecision BigInt::GetVector() const {
    return num;
}

bool BigInt::IsSigned() const{
    return Signed;
}

void BigInt::Print() const {
    std::cout<<GetString()<<std::endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  SET

void BigInt::SetSign(bool x){
    Signed = x;
}

void BigInt::Set(Multiprecision root){
    if(root[0] == uint_fast8_t('\xfd')){
        Signed = true;
        num.assign(root.begin() + 1, root.end());

    } else{
        num = root;
    }
}

void BigInt::Set(std::string root){
    num.clear();
    num.reserve(root.size());
    Set(ToVector(root));
}

void BigInt::Set(long long root){
    Set(std::to_string(root));

}

void BigInt::Extend(std::string root){
    for(unsigned int i = 0; i <root.size(); ++i){
        num.push_back(uint_fast8_t(root[i]));
    }
}