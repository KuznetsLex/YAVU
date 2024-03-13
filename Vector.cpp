#include "Vector.h"

Vector::Vector(size_t size) : arr(new int[size]), len(size) {
    assert((arr != nullptr) && "ERROR: Arr is null");
    assert((len > 0) && "ERROR: Len should be positive");
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

Vector::Vector(size_t size, int n) : arr(new int[size]), len(size) {
    assert((arr != nullptr) && "ERROR: Arr is null");
    assert((len > 0) && "ERROR: Len should be positive");
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}

Vector::Vector(Vector const &vector) : arr(new int[vector.len]), len(vector.len) {
    assert((vector.arr != nullptr) && "ERROR: Arr is null");
    assert((vector.len > 0) && "ERROR: Len should be positive");
    for (int i = 0; i < len; i++) {
        arr[i] = vector.arr[i];
    }
}

Vector::Vector(Vector &&vector) : arr(vector.arr), len(vector.len) {
    vector.arr = nullptr;
    vector.len = 0;
}

Vector::~Vector() {
    delete[] arr;
}

size_t Vector::getLen() const {
    return len;
}

int *Vector::getArr() const {
    int* copyArr = new int[len];
    for (int i = 0; i < len; i++) {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
    out << "Length: " << vector.getLen() << "; ";
    out << "Elems: ";
    for (int i = 0; i < vector.getLen(); i++) {
        out << i << ": " << vector.getArr()[i] << ", ";
    }
    out << std::endl;
    return out;
}