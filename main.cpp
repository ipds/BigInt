//This is example usage of BigInt

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <gtest/gtest.h>
#include "../src/BigInt.h"
using namespace std;
int main(){
    BigInt foo("123");
    BigInt bar("246");
    cout<< foo - bar<<endl;
    return 0;
}