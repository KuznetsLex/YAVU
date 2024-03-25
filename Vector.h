#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

#include <iostream>

class Vector {
private:
    int *arr;
    size_t len;
    size_t capacityValue = 0;
public:
    explicit Vector(size_t size = 10);

    Vector(size_t size, int n);

    Vector(Vector const &vector);

    Vector(Vector &&vector);

    Vector(size_t size, size_t capacity, int n);

    ~Vector();

    size_t getLen() const;

    void setLen(size_t len_);

    int *getArr() const;

    int &operator[](int i) const;

    void resize(size_t newSize);

    Vector &operator=(const Vector &vector);

    Vector &operator=(Vector &&other);

    bool operator==(const Vector &vector) const;

    bool operator!=(const Vector &vector) const;

    class ComparedDifferentLengthException : public std::exception {
        const char *message;
    public:
        ComparedDifferentLengthException(const char *theMessage) : message(theMessage) {}

        const char *what() const noexcept { return message; }
    };

    bool operator<(const Vector &vector) const;

    bool operator<=(const Vector &vector) const;

    bool operator>(const Vector &vector) const;

    bool operator>=(const Vector &vector) const;

    Vector operator+(const Vector &vector) const;

    void reserve(size_t n);

    size_t capacity() const;

    void pushBack(int x);

    int popBack();
};

std::istream &operator>>(std::istream &in, Vector *vector);

std::ostream &operator<<(std::ostream &out, const Vector *vector);

#endif
