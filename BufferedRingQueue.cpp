#include "BufferedRingQueue.h"

// Пользователь должен ввести длину очереди без учета буферного элемента
BufferedRingQueue::BufferedRingQueue(int len_) {
    assert((len_ > 0) && "Assertion failed: size should be positive");
    try {
        len = len_ + 1;
        arr = new int[len_];
        head = 0;
        tail = 0;
    } catch (std::bad_alloc &e) {
        arr = nullptr;
        throw e;
    }
}

void BufferedRingQueue::add(int elem) {
    if(((tail + 1) % len) == head) throw std::overflow_error("Assertion failed: queue is full");
    arr[tail] = elem;
    tail = (tail + 1) % len;
}

int BufferedRingQueue::pop() {
    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
    int elem = arr[head];
    arr[head] = 0;
    head = (head + 1) % len;
    return elem;
}

int BufferedRingQueue::getElem() const{
    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
    return arr[head];
}

int BufferedRingQueue::getQueueCurLen() const {
    if (tail < head) return len - head + tail;
    return tail - head;
}

void BufferedRingQueue::makeEmpty() {
    while(!isEmpty()) {
        pop();
    }
    head = 0;
    tail = 0;
}

bool BufferedRingQueue::isEmpty() const {
    return head == tail;
}

int BufferedRingQueue::getHead() const {
    return head;
}

int BufferedRingQueue::getTail() const {
    return tail;
}

int BufferedRingQueue::getLen() const {
    return len;
}

int BufferedRingQueue::getElemAtIndex(int index) const{
    if (index >= tail || index < head)
    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
    return arr[index];
}