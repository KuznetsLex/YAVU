#include <iostream>
#include "Vector.h"

Vector f(Vector vector) {
    return vector;
}

int main() {
    Vector v1;
    Vector v2(3, 3);
    Vector v3(v2);
    v2.getArr()[0] = 1;
    Vector v4 = f(v2);
    std::cout << v4;
    std::cout << v1;
    std::cout << v2;
    std::cout << v3;
    std::cout << v4;
    return 0;
}

