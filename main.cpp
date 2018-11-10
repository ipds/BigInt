//This is example usage of BigInt

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <gtest/gtest.h>
#include "BigInt.h"
using namespace std;

int main(){
    BigInt foo(6721673);
    cout<< foo / 3 << endl;
    return 0;
}