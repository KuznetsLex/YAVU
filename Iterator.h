#ifndef LAB2_ITERATOR_H
#define LAB2_ITERATOR_H

#include "BufferedRingQueue.h"

template<typename T>
class Iterator {
private:
    const BufferedRingQueue<T>* bufferedRingQueue;
    int currentIndex;
    bool isEnd;
public:
    explicit Iterator(const BufferedRingQueue<T> *rb);
    void start();
    void next();
    bool finish() const;
    int getValue();
};

#endif //LAB2_ITERATOR_H
