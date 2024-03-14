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

void Vector::setLen(size_t len_) {
    assert((len > 0) && "ERROR: length should be positive");
    Vector::len = len_;
}

int *Vector::getArr() const {
    int *copyArr = new int[len];
    for (int i = 0; i < len; i++) {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int &Vector::operator[](int i) const {
    assert((i >= 0) && "ERROR: Wrong input! Index should be nonnegative.");
    return arr[i];
}

void Vector::resize(size_t newSize) {
    int *newArr = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        if (i < len) {
            newArr[i] = arr[i];
        } else {
            newArr[i] = 0;
        }
    }
    delete[] arr;
    arr = newArr;
    len = newSize;
}

Vector &Vector::operator=(Vector &&other) {
    if (this == &other) { return *this; }
    std::swap(arr, other.arr);
    std::swap(len, other.len);
    return *this;
}

Vector &Vector::operator=(const Vector &vector) {
    if (this == &vector) { return *this; }
    Vector copy(vector);
    std::swap(arr, copy.arr);
    std::swap(len, copy.len);
    return *this;
}

bool Vector::operator==(const Vector &vector) {
    if (len != vector.len) { throw ComparedDifferentLengthException("ERROR: Compared vectors have different length!"); }
    for (int i = 0; i < len; i++) {
        if (arr[i] != vector.arr[i]) { return false; }
    }
    return true;
}

bool Vector::operator!=(const Vector &vector) {
    if (len != vector.len) { throw ComparedDifferentLengthException("ERROR: Compared vectors have different length!"); }
    for (int i = 0; i < len; i++) {
        if (arr[i] == vector.arr[i]) { return false; }
    }
    return true;
}

bool Vector::operator<(const Vector &vector) {
    int minLen = int(vector.len);
    if (len < minLen) { minLen = int(len); }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] >= vector.arr[i]) { return false; }
    }
    return true;
}

bool Vector::operator<=(const Vector &vector) {
    int minLen = int(vector.len);
    if (len < minLen) { minLen = int(len); }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] > vector.arr[i]) { return false; }
    }
    if (len > vector.len) { return false; }
    return true;
}

bool Vector::operator>(const Vector &vector) {
    int minLen = int(vector.len);
    if (len < minLen) { minLen = int(len); }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] <= vector.arr[i]) { return false; }
    }
    return true;
}

bool Vector::operator>=(const Vector &vector) {
    size_t minLen = vector.len;
    if (len < minLen) { minLen = len; }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] < vector.arr[i]) { return false; }
    }
    if (len < vector.len) { return false; }
    return true;
}

Vector Vector::operator+(const Vector &vector) const {
    size_t maxLen = vector.len;
    size_t minLen = len;
    if (len > maxLen) {
        maxLen = len;
        minLen = vector.len;
    }
    Vector sumVector(maxLen);
    for (int i = 0; i < maxLen; i++) {
        if (i < minLen) {
            sumVector[i] = arr[i] + vector[i];
        } else {
            if (maxLen == len) { sumVector[i] = arr[i]; }
            else { sumVector[i] = vector.arr[i]; }
        }
    }
    return sumVector;
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

std::istream &operator>>(std::istream &in, Vector &vector) {
    size_t len;
    int elem;
    std::cout << "len: ";
    in >> len;
    vector.setLen(len);
    vector.resize(len);
    for (int i = 0; i < len; i++) {
        in >> elem;
        vector[i] = elem;
    }
    return in;
}