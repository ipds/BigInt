#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt foo(20);
    BigInt bar(5);
    cout<<foo.Divide(5)<<endl;
    return 0;
}