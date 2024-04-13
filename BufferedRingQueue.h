#ifndef LAB2_BUFFEREDRINGQUEUE_H
#define LAB2_BUFFEREDRINGQUEUE_H

#include <iostream>

class BufferedRingQueue {
private:
    int* arr;
    int len;
    int head;
    int tail;
public:
    explicit BufferedRingQueue(int len);
    void add(int elem);
    int pop();
    int getElem() const;
    int getQueueCurLen() const;
    void makeEmpty();
    bool isEmpty() const;
    int getHead() const;
    int getTail() const;
    int getElemAtIndex(int index) const;
    int getLen() const;
};

#endif //LAB2_BUFFEREDRINGQUEUE_H
