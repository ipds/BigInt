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
    BigInt foo("12367834629427847942978024");
    BigInt bar("7775877562728");
    cout<< foo - bar<<endl;
    return 0;
}