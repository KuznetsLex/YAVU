#include <iostream>
#include "BufferedRingQueue.h"
#include "Iterator.h"

int main() {
    BufferedRingQueue<int> queue1(10);
    std::cout << "isEmpty:  " << queue1.isEmpty() << std::endl;
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << std::endl;
    for (int i = 1; i < 11; ++i) {
        queue1.add(i);
    }
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << "isEmpty:  " << queue1.isEmpty() << std::endl;
    std::cout << "getElem: " << queue1.getElem() << std::endl;
    std::cout << "pop:  " << queue1.pop() << std::endl;
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << std::endl;
    queue1.add(11);
    std::cout << "added elem: 10" << std::endl;
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << "pop:  " << queue1.pop() << std::endl;
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << "pop:  " << queue1.pop() << std::endl;
    std::cout << "len: " << queue1.getQueueCurLen() << std::endl;
    std::cout << std::endl;
//
//    Iterator iterator1(&queue1);
//    iterator1.start();
//    while (!iterator1.finish()) {
//        std::cout << iterator1.getValue() << std::endl;
//        iterator1.next();
//    }
//    std::cout << std::endl;
//
//    BufferedRingQueue queue2(1);
//    queue2.add(1);
//    queue2.pop();
//    queue2.add(1);
//    Iterator iterator2(&queue2);
//    iterator2.start();
//    while (!iterator2.finish()) {
//        std::cout << iterator2.getValue() << std::endl;
//        iterator2.next();
//    }
//    std::cout << std::endl;
//
//    BufferedRingQueue queue3(3);
//    queue3.add(1);
//    queue3.pop();
//    queue3.add(1);
//    queue3.pop();
//    queue3.add(2);
////    queue3.pop();
////    queue3.add(3);
//    queue3.add(3);
//    Iterator iterator3(&queue3);
//    iterator3.start();
//    while (!iterator3.finish()) {
//        std::cout << iterator3.getValue() << std::endl;
//        iterator3.next();
//    }
//    std::cout << std::endl;
    return 0;
}
