#include "Vector.h"

Vector::Vector(size_t size) try {
    assert((size >= 0) && "ERROR: Len should be nonnegative");
    arr = new int[size];
    len = size;
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}
catch(std::bad_alloc e) {
    throw e;
}

Vector::Vector(size_t size, int n) try {
    assert((size >= 0) && "ERROR: Len should be nonnegative");
    arr = new int[size];
    len = size;
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}
catch(std::bad_alloc e) {
    throw e;
}

Vector::Vector(Vector const &vector) try {
//    assert((vector.len >= 0) && "ERROR: Len should be nonnegative");
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
    assert((&vector != nullptr)&& "Vector is garbage");
    arr = new int[vector.len];
    len = vector.len;
    for (int i = 0; i < len; i++) {
        arr[i] = vector.getArr()[i];
    }
}
catch(std::bad_alloc e) {
    throw e;
}

Vector::Vector(Vector &&vector) {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: Len should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    arr = vector.arr;
    len = vector.len;
    vector.arr = nullptr;
    vector.len = 0;
}

Vector::Vector(size_t size, size_t capacity, int n) try {
//    assert((arr != nullptr) && "ERROR: Arr is null");
    assert((size >= 0) && "ERROR: Len should be positive");
    assert((capacity > 0) && "ERROR: Capacity should be positive");
    len = size;
    capacityValue = capacity;
    arr = new int[size+capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}
catch(std::bad_alloc e) {
    throw e;
}

Vector::~Vector() {
    delete[] arr;
}

size_t Vector::getLen() const {
    return len;
}

void Vector::setLen(size_t len_) {
    assert((len_ >= 0) && "ERROR: length should be positive");
    Vector::len = len_;
}

int *Vector::getArr() const {
    try {
        int *copyArr = new int[len];
        for (int i = 0; i < len; i++) {
            copyArr[i] = arr[i];
        }
        return copyArr;
    }
    catch(std::bad_alloc e) {
        throw e;
    }
}

int &Vector::operator[](int i) const {
    assert((i >= 0) && "ERROR: Wrong input! Index should be nonnegative.");
    assert((i < len) && "ERROR: Index out of bound");
    return arr[i];
}

void Vector::resize(size_t newSize) {
    assert((newSize > 0) && "ERROR: length should be positive");
    //  блок if - старый resize; вместе с блоком else - новый resize
    try {
        if (newSize > len + capacityValue) {
            int *newArr = new int[newSize];
            for (int i = 0; i < len; i++) {
                newArr[i] = arr[i];

            }
            delete[] arr;
            arr = newArr;
        } else {
            capacityValue -= (newSize - len);
            if (len < newSize) {
                for (int i = len; i < newSize; i++) {
                    arr[i] = 0;
                }
            }
        }
        len = newSize;
    }
    catch(std::bad_alloc e) {
        throw e;
    }
}

Vector &Vector::operator=(Vector &&other) {
//    assert((other.arr != nullptr) && "ERROR: Arr is null");
//    assert((other.len >= 0) && "ERROR: length should be positive");
    assert((&other != nullptr)&& "Vector is garbage");
    if (this == &other) { return *this; }
    std::swap(arr, other.arr);
    std::swap(len, other.len);
    return *this;
}

Vector &Vector::operator=(const Vector &vector) {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    if (this == &vector) { return *this; }
    Vector copy(vector);
    std::swap(arr, copy.arr);
    std::swap(len, copy.len);
    return *this;
}

bool Vector::operator==(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    if (len != vector.len) { throw ComparedDifferentLengthException("ERROR: Compared vectors have different length!"); }
    for (int i = 0; i < len; i++) {
        if (arr[i] != vector.arr[i]) { return false; }
    }
    return true;
}

bool Vector::operator!=(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    return !(vector == *this);
}

bool Vector::operator<(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    return !(*this >= vector);
}

bool Vector::operator<=(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    if (len == vector.len) {
        if (vector == *this) { return true; }
    }
    int minLen = int(vector.len);
    if (len < minLen) { minLen = int(len); }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] > vector.arr[i]) { return false; }
        else if (arr[i] < vector.arr[i]) { return true; }
    }
    if (len > vector.len) { return false; }
    return true;
}

bool Vector::operator>(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    return !(*this <= vector);
}

bool Vector::operator>=(const Vector &vector) const {
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    assert((&vector != nullptr)&& "Vector is garbage");
    if (len == vector.len) {
        if (vector == *this) { return true; }
    }
    size_t minLen = vector.len;
    if (len < minLen) { minLen = len; }
    for (int i = 0; i < minLen; i++) {
        if (arr[i] < vector.arr[i]) { return false; }
        else if (arr[i] > vector.arr[i]) { return true; }
    }
    if (len < vector.len) { return false; }
    return true;
}

Vector Vector::operator+(const Vector &vector) const {
    assert((&vector != nullptr)&& "Vector is garbage");
//    assert((vector.arr != nullptr) && "ERROR: Arr is null");
//    assert((vector.len >= 0) && "ERROR: length should be positive");
    Vector newVector(0);

    for (int i = 0; i < len; i++) {
        newVector.pushBack(arr[i]);
    }
    for (int i = 0; i < vector.len; i++) {
        newVector.pushBack(vector.arr[i]);
    }
    return newVector;
}

void Vector::reserve(size_t n) {
    assert((n > 0) && "ERROR: reserved space should be positive");
    try {
        int *newArr = new int[len + n];
        for (int i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacityValue = n;
    } catch(std::bad_alloc e) {
        throw e;
    }
}

size_t Vector::capacity() const {
    return capacityValue;
}

void Vector::pushBack(int x) {
    resize(len + 1);
    arr[len - 1] = x;
}

int Vector::popBack() {
    int returnValue = arr[len - 1];
    resize(len - 1);
    return returnValue;
}

std::ostream &operator<<(std::ostream &out, const Vector *vector) {
//    assert((vector.getArr() != nullptr) && "ERROR: Arr is null");
//    assert((vector.getLen() >= 0) && "ERROR: Len should be nonnegative");
    assert((vector != nullptr)&& "Vector is garbage");
    out << "Length: " << (*vector).getLen() << "; ";
    out << "Elems: ";
    for (int i = 0; i < (*vector).getLen(); i++) {
        out << i << ": " << (*vector)[i] << ", ";
    }
    out << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Vector *vector) {
    assert((vector != nullptr)&& "Vector is garbage");
    size_t len;
    int elem;
    std::cout << "len: ";
    in >> len;
    (*vector).setLen(len);
    (*vector).resize(len);
    for (int i = 0; i < len; i++) {
        std::cout << "elem " << i << ": ";
        in >> elem;
        (*vector)[i] = elem;
    }
    return in;
}