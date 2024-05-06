#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include "Node.h"

class Iterator {
public:
    virtual void first() = 0;
    virtual int currentItem() = 0;
    virtual void next() = 0;
//    virtual void prev() = 0;
    virtual bool isDone() = 0;

    // СОКРЫТЬ!
//    virtual Node* getCurrentNode() = 0;
//    virtual void setCurrentNode(Node*) = 0;
};


#endif