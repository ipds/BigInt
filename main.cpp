//This is example usage of BigInt

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "BigInt.h"
using namespace std;

int main(){
    BigInt foo("43432");
    foo.Divide({2});
    cout << foo << endl;
    return 0;
}