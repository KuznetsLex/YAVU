//#include "BufferedRingQueue.h"
//
//// Пользователь должен ввести длину очереди без учета буферного элемента
//template<typename T>
//BufferedRingQueue<T>::BufferedRingQueue(int len_) {
//    assert((len_ > 0) && "Assertion failed: size should be positive");
//    try {
//        len = len_ + 1;
//        arr = new int[len_];
//        head = 0;
//        tail = 0;
//    } catch (std::bad_alloc &e) {
//        arr = nullptr;
//        throw e;
//    }
//}
//
//template<typename T>
//void BufferedRingQueue<T>::add(T elem) {
//    if(((tail + 1) % len) == head) throw std::overflow_error("Assertion failed: queue is full");
//    arr[tail] = elem;
//    tail = (tail + 1) % len;
//}
//
//template<typename T>
//T BufferedRingQueue<T>::pop() {
//    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
//    int elem = arr[head];
//    arr[head] = 0;
//    head = (head + 1) % len;
//    return elem;
//}
//
//template<typename T>
//T BufferedRingQueue<T>::getElem() const{
//    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
//    return arr[head];
//}
//
//template<typename T>
//int BufferedRingQueue<T>::getQueueCurLen() const {
//    if (tail < head) return len - head + tail;
//    return tail - head;
//}
//
//template<typename T>
//void BufferedRingQueue<T>::makeEmpty() {
//    while(!isEmpty()) {
//        pop();
//    }
//    head = 0;
//    tail = 0;
//}
//
//template<typename T>
//bool BufferedRingQueue<T>::isEmpty() const {
//    return head == tail;
//}
//
//template<typename T>
//int BufferedRingQueue<T>::getHead() const {
//    return head;
//}
//
//template<typename T>
//int BufferedRingQueue<T>::getTail() const {
//    return tail;
//}
//
//template<typename T>
//int BufferedRingQueue<T>::getLen() const {
//    return len;
//}
//
//template<typename T>
//T BufferedRingQueue<T>::getElemAtIndex(int index) const{
//    if (index >= tail || index < head)
//    if(isEmpty()) throw std::underflow_error("Assertion failed: queue is empty");
//    return arr[index];
//}
