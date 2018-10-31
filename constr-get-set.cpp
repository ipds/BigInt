//
// Created by Adam Szokalski on 31/10/2018.
//

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

void BigInt::Set(Multiprecision root){
    num = root;
}

void BigInt::Set(std::string root){
    num.clear();
    num.reserve(root.size());
    Signed = (root[0] == '-');
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