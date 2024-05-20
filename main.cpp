#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree1(1);
    tree1.insert(2, std::vector<int> {0});
    tree1.insert(3, std::vector<int> {1});
    tree1.insert(4, std::vector<int> {0,0});
    tree1.insert(5, std::vector<int> {0,1});
    tree1.insert(6, std::vector<int> {1,0});
    tree1.insert(7, std::vector<int> {1,1});
    tree1.insert(8, std::vector<int> {0,1,1});
    std::cout << "tree1: " << &tree1 << std::endl;
    std::cout << "tree1 evenCount: " << tree1.evenCount() << std::endl;
    std::cout << "tree1 areAllPositive: " << tree1.areAllPositive() << std::endl;
    std::cout << "tree1 arithmeticMean: " << tree1.arithmeticMean() << std::endl;
    std::cout << "tree1 deleteLeaves: ";
    std::vector<int> cutArray = tree1.deleteLeaves();
    for (int i = 0; i < cutArray.size(); i++) {
        std::cout << cutArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "tree1: " << &tree1 << std::endl;
    std::cout << "tree1 find(7): ";
    std::vector<int> sequence1 = tree1.find(7);
    for (int i = 0; i < sequence1.size(); i++) {
        std::cout << sequence1[i] << " ";
    }
    std::cout << std::endl;
    BinaryTree tree2(tree1);
    std::cout << "tree2: " << &tree2 << std::endl;
    return 0;
}
