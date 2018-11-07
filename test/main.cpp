#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../src/BigInt.h"

using namespace std;

int main() {
    BigInt foo(23424240);
    BigInt bar(524234234);
    cout<<foo * bar<<endl;
    return 0;
}