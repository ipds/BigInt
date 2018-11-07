#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../src/BigInt.h"

using namespace std;

int main (int argc, char *argv[]){
    for (int i = 0; i < argc; ++i) {
        cout<<argv[i]<<endl;
    }
    if(argc >= 2) {
        BigInt x(argv[0]);
        BigInt y(argv[1]);
        cout << x << " + " << y << " = "<< x + y << endl;
    }
    return 0;
}