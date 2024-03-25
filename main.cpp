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
    std::cout << "v4: " << &v4;
    std::cout << "v1: " << &v1;
    std::cout << "v2: " << &v2;
    std::cout << "v3: " << &v3;
    std::cout << "v4: " << &v4;
    std::cout << std::endl;
    std::cout << "v1 size: " << v1.getLen() << std::endl;
    std::cout << "v1 capacity: " << v1.capacity() << std::endl;
    std::cout << "v1: " << &v1;
    std::cout << std::endl;
    v1[0] = 1;
    v1[9] = 9;
    v1.reserve(3);
    v1.resize(12);
    v1[11] = 11;
    std::cout << "v1 size: " << v1.getLen() << std::endl;
    std::cout << "v1 capacity: " << v1.capacity() << std::endl;
    std::cout << "v1: " << &v1;
    std::cout << std::endl;
    v1.pushBack(12);
    std::cout << "v1 size: " << v1.getLen() << std::endl;
    std::cout << "v1 capacity: " << v1.capacity() << std::endl;
    std::cout << "v1: " << &v1;
    std::cout << std::endl;
    v1.pushBack(13);
    std::cout << "v1 size: " << v1.getLen() << std::endl;
    std::cout << "v1 capacity: " << v1.capacity() << std::endl;
    std::cout << "v1: " << &v1;
    std::cout << std::endl;
    v1.popBack();
    std::cout << "v1 size: " << v1.getLen() << std::endl;
    std::cout << "v1 capacity: " << v1.capacity() << std::endl;
    std::cout << "v1: " << &v1;
    std::cout << std::endl;

    v1[2] = 5;
    std::cout << "v1: " << &v1;
    std::cout << "v2: " << &v2;
    Vector v5;
    v5 = v1+v2;
    std::cout << "v5: " << &v5;
    std::cout << std::endl;

    v4[2] = 10;
    std::cout << "v3: " << &v3;
    std::cout << "v4: " << &v4;
    bool compare1 = v3 == v4;
    std::cout << " v3 == v4: " << compare1 << std::endl;
    bool compare2 = v3 != v4;
    std::cout << " v3 != v4: " << compare2 << std::endl;
    bool compare3 = v3 <= v4;
    std::cout << " v3 <= v4: " << compare3 << std::endl;
    bool compare4 = v3 < v4;
    std::cout << " v3 < v4: " << compare4 << std::endl;
    bool compare5 = v3 >= v4;
    std::cout << " v3 >= v4: " << compare5 << std::endl;
    bool compare6 = v3 > v4;
    std::cout << " v3 > v4: " << compare6 << std::endl;
    std::cout << std::endl;

    std::cout << "v1: " << &v1;
    std::cout << "v2: " << &v2;
    bool compare9 = v1 <= v2;
    std::cout << " v1 <= v2: " << compare9 << std::endl;
    bool compare10 = v1 < v2;
    std::cout << " v1 < v2: " << compare10 << std::endl;
    bool compare11 = v1 >= v2;
    std::cout << " v1 >= v2: " << compare11 << std::endl;
    bool compare12 = v1 > v2;
    std::cout << " v1 > v2: " << compare12 << std::endl;
    std::cout << std::endl;

    v1[0] = 3;
    v1[1] = 3;
    v1[2] = 3;
    std::cout << "v1: " << &v1;
    std::cout << "v2: " << &v2;
    bool compare13 = v1 <= v2;
    std::cout << " v1 <= v2: " << compare13 << std::endl;
    bool compare14 = v1 < v2;
    std::cout << " v1 < v2: " << compare14 << std::endl;
    bool compare15 = v1 >= v2;
    std::cout << " v1 >= v2: " << compare15 << std::endl;
    bool compare16 = v1 > v2;
    std::cout << " v1 > v2: " << compare16 << std::endl;
    std::cout << std::endl;

    std::cin >> &v5;
    std::cout << "v5: " << &v5;
    return 0;
}

