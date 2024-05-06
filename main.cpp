#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list1;
    Iterator* iterator = list1.createIterator();
    std::cout << "getLen: " << list1.getLen() << std::endl;
    std::cout << "isEmpty: " << list1.isEmpty() << std::endl;
    list1.insert(0, iterator);
    for (int i = 1; i < 10; ++i) {
        list1.remove(iterator);
        list1.insert(i, iterator);
    }
    std::cout << "getLen: " << list1.getLen() << std::endl;
    std::cout << "isEmpty: " << list1.isEmpty() << std::endl;
    std::cout << &list1 << std::endl;
    std::cout << std::endl;

    LinkedList list2;
    iterator = list2.createIterator();
    std::cout << "getLen: " << list2.getLen() << std::endl;
    std::cout << "isEmpty: " << list2.isEmpty() << std::endl;
    list2.insert(1, iterator);
    list2.remove(iterator);
    std::cout << "getLen: " << list2.getLen() << std::endl;
    std::cout << "isEmpty: " << list2.isEmpty() << std::endl;
    std::cout << &list2 << std::endl;
    std::cout << std::endl;

    LinkedList list3;
    iterator = list3.createIterator();
    std::cout << "getLen: " << list3.getLen() << std::endl;
    std::cout << "isEmpty: " << list3.isEmpty() << std::endl;
    for (int i = 0; i < 10; ++i) {
        list3.insert(i, iterator);
        list3.remove(iterator);
    }
    std::cout << "getLen: " << list3.getLen() << std::endl;
    std::cout << "isEmpty: " << list3.isEmpty() << std::endl;
    std::cout << &list3 << std::endl;
    std::cout << std::endl;

    LinkedList list4;
    iterator = list4.createIterator();
    std::cout << "getLen: " << list4.getLen() << std::endl;
    std::cout << "isEmpty: " << list4.isEmpty() << std::endl;
    for (int i = 1; i < 10; ++i) {
        list4.insert(i, iterator);
    }
    std::cout << "getLen: " << list4.getLen() << std::endl;
    std::cout << "isEmpty: " << list4.isEmpty() << std::endl;
    std::cout << &list4 << std::endl;

    LinkedList list5;
    iterator = list5.createIterator();
    std::cout << "getLen: " << list5.getLen() << std::endl;
    std::cout << "isEmpty: " << list5.isEmpty() << std::endl;
    for (int i = 1; i < 10; ++i) {
        list5.insert(i, iterator);
    }
    std::cout << "getLen: " << list5.getLen() << std::endl;
    std::cout << "isEmpty: " << list5.isEmpty() << std::endl;
    list5.makeEmpty();
    std::cout << "getLen: " << list5.getLen() << std::endl;
    std::cout << "isEmpty: " << list5.isEmpty() << std::endl;
    std::cout << &list5 << std::endl;
    iterator->first();
    for (int i = 1; i < 10; ++i) {
        list5.insert(i, iterator);
    }
    std::cout << "getLen: " << list5.getLen() << std::endl;
    std::cout << "isEmpty: " << list5.isEmpty() << std::endl;
    std::cout << &list5 << std::endl;

    LinkedList list6;
    iterator = list6.createIterator();
    std::cout << "getLen: " << list6.getLen() << std::endl;
    std::cout << "isEmpty: " << list6.isEmpty() << std::endl;
    for (int i = 1; i < 10; ++i) {
        list6.insert(i, iterator);
    }
    std::cout << "Value 5 find: " << list5.find(5)->currentItem() << std::endl;
    std::cout << "Value 2 find: " << list5.find(2)->currentItem() << std::endl;
    std::cout << "getLen: " << list5.getLen() << std::endl;
    std::cout << "isEmpty: " << list5.isEmpty() << std::endl;
    std::cout << &list5 << std::endl;
//    std::cout << "Value 11 find: " << list5.find(11)->currentItem() << std::endl;

    LinkedList list7(list6);
    std::cout << &list7 << std::endl;

    list7 = list1;
    std::cout << &list7 << std::endl;
    return 0;
}
