#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt foo(3455);
    BigInt bar(28838);
    cout<<foo-bar<<endl;
    return 0;
}

//3455-28838 = -25383