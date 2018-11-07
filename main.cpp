//
// Created by Adam Szokalski on 07/11/2018.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <gtest/gtest.h>
#include "../src/BigInt.h"
using namespace std;
int main(){
    BigInt foo(123);
    BigInt bar(124);
    cout<< foo - bar<<endl;
    return 0;
}