#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt foo(1e12);
    BigInt bar(1e13);
    cout<<foo.IsGreater(bar)<<endl;
    return 0;
}