#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt foo(10);
    BigInt bar(2);
    cout<<foo-bar+2<<endl;
    return 0;
}