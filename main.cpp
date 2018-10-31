#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "BigInt.h"

int main() {
    BigInt foo{};
    BigInt bar{};

    std::cout << "Set foo: ";
    std::cin >> foo;
    std::cout << std::endl;

    std::cout << "Set bar: ";
    std::cin >> bar;
    std::cout << std::endl;

    std::cout << foo << " + " << bar <<" = " << foo + bar << std::endl;
    return 0;
}