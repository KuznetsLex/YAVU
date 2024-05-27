#ifndef LAB5_BINARYTREE_H
#define LAB5_BINARYTREE_H


#include <ostream>
#include "TreeElem.h"

class BinaryTree {
private:
    TreeElem* root;

public:
    explicit BinaryTree(int rootElem = 0);

    BinaryTree(BinaryTree const &treeOrig);

    TreeElem* getRoot() const;

    ~BinaryTree();

    BinaryTree &operator=(BinaryTree const &treeOrig);

    int insert(int x, const std::vector<int>& sequence);

    int evenCount();

    bool areAllPositive();

    std::vector<int>& deleteLeaves();

    double arithmeticMean();

    std::vector<int>& find(int x);

    bool isBinarySearch(const TreeElem* theRoot);

    void printByLevels(std::ostream &out, const TreeElem* root);
};

std::ostream &operator<<(std::ostream &out, BinaryTree *tree);

#endif
