#include "LinkedList.h"


LinkedList::LinkedList() {
    try{
        bufNode = new Node;
        bufNode->data = NAN;
        bufNode->prev = bufNode;
        bufNode->next = bufNode;
    } catch (std::bad_alloc &e) {
        throw e;
    }
}

LinkedList::LinkedList(LinkedList &listOrig) try {
    assert((&listOrig != nullptr)&& "LinkedList is garbage");
    bufNode = new Node;
    bufNode->data = NAN;
    bufNode->prev = bufNode;
    bufNode->next = bufNode;
    Iterator* iteratorOrig = listOrig.createIterator();
    Iterator* iteratorNew = this->createIterator();
    iteratorOrig->first();
    iteratorNew->first();
    while(!iteratorOrig->isDone()) {
        this->insert(iteratorOrig->currentItem(), iteratorNew);
        iteratorOrig->next();
    }
    this->insert(iteratorOrig->currentItem(), iteratorNew);
}
catch(std::bad_alloc &e) {
    throw e;
}

LinkedList::LinkedList(LinkedList&& listOrig) noexcept {
    assert((&listOrig != nullptr)&& "LinkedList is garbage");
    bufNode = listOrig.bufNode;
    listOrig.bufNode->data = NAN;
    listOrig.bufNode->prev = nullptr;
    listOrig.bufNode->next = nullptr;
}

LinkedList &LinkedList::operator=(LinkedList &listOrig) {
    assert((&listOrig != nullptr)&& "LinkedList is garbage");
    if (this == &listOrig) { return *this; }
    LinkedList copy(listOrig);
    std::swap(bufNode, copy.bufNode);
    return *this;
}

void LinkedList::insert(int value, Iterator *it) {
    assert((it != nullptr) && "Assertion failed: iterator is garbage");
    try{
        auto* listIterator = dynamic_cast<ListIterator*>(it);
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = listIterator->getCurrentNode()->next;
        newNode->prev = listIterator->getCurrentNode();
        listIterator->getCurrentNode()->next->prev = newNode;
        listIterator->getCurrentNode()->next = newNode;
        listIterator->next();
    } catch (std::bad_alloc &e) {
        throw e;
    }

}

int LinkedList::remove(Iterator *it) {
    if (!isEmpty()) {
        auto* listIterator = dynamic_cast<ListIterator*>(it);
        int returnValue = listIterator->getCurrentNode()->data;
        listIterator->getCurrentNode()->data = 0;
        listIterator->getCurrentNode()->prev->next = listIterator->getCurrentNode()->next;
        listIterator->getCurrentNode()->next->prev = listIterator->getCurrentNode()->prev;
        Node* tmp = listIterator->getCurrentNode()->prev;

        listIterator->getCurrentNode()->next = nullptr;
        listIterator->getCurrentNode()->prev = nullptr;
//        listIterator->prev();
        delete(listIterator->getCurrentNode());
        listIterator->setCurrentNode(tmp);
        return returnValue;
    }
}

Iterator *LinkedList::find(int value) {
    Iterator* iterator = createIterator();
    iterator->first();
    while(!iterator->isDone()) {
        if (iterator->currentItem() == value) {
            return iterator;
        }
        iterator->next();
    }
//    throw std::out_of_range("Assertion failed: iterator is at the end, value not found");
    assert((false) && "Assertion failed: iterator is at the end, value not found");
}

void LinkedList::makeEmpty() {
    Iterator* iterator = createIterator();
    iterator->first();
    while(!iterator->isDone()) {
        remove(iterator);
        iterator->next();
    }
    remove(iterator);
}

bool LinkedList::isEmpty() {
    return (bufNode == bufNode->next && bufNode == bufNode->prev);
}

int LinkedList::getLen() {
    if (isEmpty()) {
        return 0;
    }
    Iterator* iterator = createIterator();
    iterator->first();
    int len = 1;
    while(!iterator->isDone()) {
        len++;
        iterator->next();
    }
    return len;
}

Iterator *LinkedList::createIterator() {
    auto* iterator = new ListIterator(this);
    return iterator;
}

std::ostream &operator<<(std::ostream &out, LinkedList *list) {
    assert((list != nullptr)&& "Assertion failed: list is garbage");
    if (list->isEmpty()) {
        out << "List is empty";
        return out;
    }
    Iterator* iterator = list->createIterator();
    iterator->first();
    while(!iterator->isDone()) {
        out << iterator->currentItem() << " ";
        iterator->next();
    }
    out << iterator->currentItem() << " ";
    out << std::endl;
    return out;
}


LinkedList::ListIterator::ListIterator(LinkedList *list) {
    assert((list != nullptr) && "Assertion failed: list is garbage");
    iteratedLinkedList = list;
    first();
}

void LinkedList::ListIterator::first() {
    currentNode = iteratedLinkedList->bufNode->next;
}

int LinkedList::ListIterator::currentItem() {
    assert((!iteratedLinkedList->isEmpty()) && "Assertion failed: linkedList is empty");
    return currentNode->data;
}

void LinkedList::ListIterator::next() {
    if (isDone()) {
        throw std::out_of_range("Assertion failed: iterator is at the end");
    } else {
        currentNode = currentNode->next;
    }
}

//void LinkedList::ListIterator::prev() {
//    currentNode = currentNode->prev;
//}

bool LinkedList::ListIterator::isDone() {
    return (currentNode->next == iteratedLinkedList->bufNode);
}

Node *LinkedList::ListIterator::getCurrentNode() {
    return currentNode;
}

void LinkedList::ListIterator::setCurrentNode(Node* node) {
    currentNode = node;
}

