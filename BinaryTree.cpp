#include <iostream>
#include "BinaryTree.h"

void evenCountWrapper(const TreeElem* theRoot, int* counter) {
    if (!theRoot) {
        return;
    }
    if (theRoot->info % 2 == 0) { (*counter)++; }
    evenCountWrapper(theRoot -> left, counter);
    evenCountWrapper(theRoot -> right, counter);
}

int BinaryTree::evenCount() {
    int* counter = new int(0);
    evenCountWrapper(root, counter);
    return *counter;
}

void areAllPositiveWrapper(const TreeElem* theRoot, bool* flag) {
    if (!theRoot) {
        return;
    }
    if (theRoot->info <= 0) { (*flag) = false; return; }
    areAllPositiveWrapper(theRoot -> left, flag);
    areAllPositiveWrapper(theRoot -> right, flag);
}

bool BinaryTree::areAllPositive() {
    bool* flag = new bool(true);
    areAllPositiveWrapper(root, flag);
    return *flag;
}

void deleteLeavesWrapper(TreeElem* theRoot, std::vector<int>* cutArray) {
    if (!theRoot) {
        return;
    }
    if (theRoot->left) {
        if (!theRoot->left->left && !theRoot->left->right) {
            cutArray->push_back(theRoot->left->info);
            delete(theRoot->left);
            theRoot->left = nullptr;
        }
    }
    if (theRoot->right) {
        if (!theRoot->right->left && !theRoot->right->right) {
            cutArray->push_back(theRoot->right->info);
            delete (theRoot->right);
            theRoot->right = nullptr;
        }
    }
    deleteLeavesWrapper(theRoot -> left, cutArray);
    deleteLeavesWrapper(theRoot -> right, cutArray);
}

std::vector<int>& BinaryTree::deleteLeaves() {
    auto* cutArray = new std::vector<int>();
    deleteLeavesWrapper(root, cutArray);
    return *cutArray;
}

void arithmeticMeanWrapper(const TreeElem* theRoot, int* counter, int* sum) {
    if (!theRoot) {
        return;
    }
    (*counter)++;
    (*sum) += theRoot->info;
    arithmeticMeanWrapper(theRoot -> left, counter, sum);
    arithmeticMeanWrapper(theRoot -> right, counter, sum);
}

double BinaryTree::arithmeticMean() {
    int* counter = new int(0);
    int* sum = new int(0);
    arithmeticMeanWrapper(root, counter, sum);
    return (double)(*sum)/(*counter);
}

bool findWrapper(TreeElem* root, std::vector<int>& sequence, int x)
{
    if (!root)
        return false;
    if (root->info == x)
        return true;
    if (findWrapper(root->left, sequence, x)) {
        sequence.push_back(0);
        return true;
    }
    else if (findWrapper(root->right, sequence, x)) {
        sequence.push_back(1);
        return true;
    }
    return false;
}

std::vector<int>& BinaryTree::find(int x) {
    auto* sequence = new std::vector<int>();
    findWrapper(root, *sequence, x);
    std::reverse(sequence->begin(), sequence->end());
    if (sequence->empty() && root->info != x) {
        sequence->push_back(-1);
    }
    return *sequence;
}

TreeElem* BinaryTree::getRoot() const {
    return root;
}

void printLeftRight(std::ostream &out, const TreeElem* root)
{
    if (!root) { return; }
    printLeftRight(out, root -> left);
    out << root -> info << " ";
    printLeftRight(out, root -> right);
}

std::ostream &operator<<(std::ostream &out, BinaryTree *tree)
{
    printLeftRight(out, tree->getRoot());
    return out;
}

BinaryTree::BinaryTree(int rootElem) {
    root = new TreeElem(rootElem);
}

void clearElems(TreeElem* root) {
    if (!root) return;
    clearElems(root -> left); clearElems(root -> right); delete root;
}

void clear(TreeElem*& root) {
    clearElems(root);
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    clear(root);
}

TreeElem* copyTreeByRoot(const TreeElem* root) {
    if (!root) { return nullptr; }
    auto* rootCopy = new TreeElem(root -> info); try {
        rootCopy -> left = copyTreeByRoot(root -> left);
        rootCopy -> right = copyTreeByRoot(root -> right);
        return rootCopy;
    } catch (std::bad_alloc &e) {
        clear(rootCopy);
        throw;
    }
}

BinaryTree::BinaryTree(BinaryTree const &treeOrig) {
    root = copyTreeByRoot(treeOrig.root);
}

BinaryTree &BinaryTree::operator=(BinaryTree const &treeOrig) {
    assert((&treeOrig != nullptr)&& "LinkedList is garbage");
    if (this == &treeOrig) { return *this; }
    BinaryTree copy(treeOrig);
    std::swap(root, copy.root);
    return *this;
}

int BinaryTree::insert(int x, const std::vector<int>& sequence) {
    TreeElem* curNode = root;
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == 0) {
            if (curNode->left == nullptr) {
                if (i == sequence.size() - 1) {
                    auto * newNode = new TreeElem(x);
                    curNode->left = newNode;
                    return 0;
                } else {
                    return -1;
                }
            } else {
                curNode = curNode->left;
                if (i == sequence.size() - 1) {
                    curNode->info = x;
                }
            }
        }
        if (sequence[i] == 1) {
            if (curNode->right == nullptr) {
                if (i == sequence.size() - 1) {
                    auto * newNode = new TreeElem(x);
                    curNode->right = newNode;
                    return 0;
                } else {
                    return -1;
                }
            } else {
                curNode = curNode->right;
                if (i == sequence.size() - 1) {
                    curNode->info = x;
                }
            }
        }
    }
    return -2;
}