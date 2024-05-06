#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include "Iterator.h"

class List {
public:
    virtual void insert(int value, Iterator* it) = 0;
    // Тип возвращаемого значения remove - int
    virtual int remove(Iterator* it) = 0;
    virtual Iterator* find(int value) = 0;
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() = 0;
    virtual int getLen() = 0;
    virtual Iterator* createIterator() = 0;
};


#endif