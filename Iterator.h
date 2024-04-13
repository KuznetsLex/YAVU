#ifndef LAB2_ITERATOR_H
#define LAB2_ITERATOR_H

#include "BufferedRingQueue.h"

class Iterator {
private:
    const BufferedRingQueue* bufferedRingQueue;
    int currentIndex;
    bool isEnd;
public:
    explicit Iterator(const BufferedRingQueue *rb);
    void start();
    void next();
    bool finish() const;
    int getValue();
};

#endif //LAB2_ITERATOR_H
