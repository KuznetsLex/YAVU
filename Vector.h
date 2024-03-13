#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

#include <iostream>

class Vector {
private:
    int* arr;
    size_t len;
public:
    explicit Vector(size_t size = 10);
    Vector(size_t size, int n);
    Vector(Vector const &vector);
    Vector(Vector&& vector);
    ~Vector();
    size_t getLen() const;
    int* getArr() const;
};
std::ostream &operator<<(std::ostream &out, const Vector &vector);


#endif
