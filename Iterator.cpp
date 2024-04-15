#include "Iterator.h"

Iterator::Iterator(const BufferedRingQueue<T> *rb) {
    assert((rb != nullptr) && "Assertion failed: queue is null");
    bufferedRingQueue = rb;
    currentIndex = bufferedRingQueue->getHead();
    if (currentIndex == bufferedRingQueue->getTail()) {
        isEnd = true;
    } else {
        isEnd = false;
    }
}

void Iterator::start() {
    currentIndex = bufferedRingQueue->getHead();
}

void Iterator::next() {
    if (isEnd) {
        throw std::out_of_range("Assertion failed: iterator is at the end");
    } else {
        currentIndex = (currentIndex + 1) % bufferedRingQueue->getLen();
    }
    if(currentIndex == bufferedRingQueue->getTail()) {
        isEnd = true;
    }
}

bool Iterator::finish() const {
    return isEnd;
}

int Iterator::getValue() {
    if (isEnd) {
        throw std::out_of_range("Assertion failed: iterator is at the end");
    }
    return bufferedRingQueue->getElemAtIndex(currentIndex);
}
