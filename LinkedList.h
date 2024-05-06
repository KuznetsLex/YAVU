#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H

#include "List.h"
#include "Iterator.h"
#include "Node.h"
#include <iostream>

class LinkedList : public List{
private:
    Node* bufNode;
public:
    explicit LinkedList();

    LinkedList(LinkedList &listOrig);

    LinkedList(LinkedList&& listOrig) noexcept ;

    LinkedList &operator=(LinkedList &listOrig);

    void insert(int value, Iterator *it) override;

    int remove(Iterator *it) override;

    Iterator *find(int value) override;

    void makeEmpty() override;

    bool isEmpty() override;

    int getLen() override;

    Iterator *createIterator() override;

    class ListIterator : public Iterator {
    private:
        LinkedList* iteratedLinkedList;
        Node* currentNode;
    public:
        explicit ListIterator(LinkedList *);

        void first() override;

        int currentItem() override;

        void next() override;

//        void prev() override;

        bool isDone() override;

        Node* getCurrentNode();

        void setCurrentNode(Node*);
    };
};

std::ostream &operator<<(std::ostream &out, LinkedList *list);


#endif