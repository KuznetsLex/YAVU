#ifndef LAB2_BUFFEREDRINGQUEUE_H
#define LAB2_BUFFEREDRINGQUEUE_H

#include <iostream>

template <typename T>
class BufferedRingQueue {
private:
    T* arr;
    int len;
    int head;
    int tail;
public:
// Пользователь должен ввести длину очереди без учета буферного элемента
    BufferedRingQueue(int len_) {
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

    void add(T elem) {
        if(((tail + 1) % len) == head) throw std::overflow_error("Assertion failed: queue is full");
        arr[tail] = elem;
        tail = (tail + 1) % len;
    }

    T pop() {
        if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
        int elem = arr[head];
        arr[head] = 0;
        head = (head + 1) % len;
        return elem;
    }

    T getElem() const{
        if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
        return arr[head];
    }

    int getQueueCurLen() const {
        if (tail < head) return len - head + tail;
        return tail - head;
    }

    void makeEmpty() {
        while(!isEmpty()) {
            pop();
        }
        head = 0;
        tail = 0;
    }

    bool isEmpty() const {
        return head == tail;
    }

    int getHead() const {
        return head;
    }

    int getTail() const {
        return tail;
    }

    int getLen() const {
        return len;
    }

    T getElemAtIndex(int index) const{
        if (index >= tail || index < head)
            if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
        return arr[index];
    }

};

#endif //LAB2_BUFFEREDRINGQUEUE_H
