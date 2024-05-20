#ifndef LAB5_BINARYTREE_H
#define LAB5_BINARYTREE_H


#include <ostream>
#include "TreeElem.h"

class BinaryTree {
private:
    TreeElem* root;

public:
    explicit BinaryTree(int rootElem);

    BinaryTree(BinaryTree &treeOrig);

    BinaryTree(BinaryTree&& treeOrig) noexcept ;

    TreeElem* getRoot() const;

    ~BinaryTree();

    BinaryTree &operator=(BinaryTree &treeOrig);

    int insert(int x, const std::vector<int>& sequence);

    int evenCount();

    bool areAllPositive();

    std::vector<int> deleteLeaves();

    double arithmeticMean();

    int* find(int x);
};

std::ostream &operator<<(std::ostream &out, BinaryTree *tree);

#endif
