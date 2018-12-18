#include <iostream>
#include "src/datum.h"

using namespace stboost;

int main() {
    datum <int> d;

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Caldela " << d.is_null() << std::endl;
    return 0;
}