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

    std::cout << std::endl;
    BinaryTree tree3(8);
    tree3.insert(6, std::vector<int> {0});
    tree3.insert(4, std::vector<int> {0,0});
    std::cout << "tree3: " << &tree3 << std::endl;

    BinaryTree tree4(10);
    tree4.insert(5, std::vector<int> {0});
    tree4.insert(16, std::vector<int> {1});
    tree4.insert(4, std::vector<int> {0,0});
    tree4.insert(7, std::vector<int> {0,1});
    tree4.insert(1, std::vector<int> {0,0,0});
    tree4.insert(11, std::vector<int> {0,0,1});
    std::cout << "tree4: " << &tree4 << std::endl;

    BinaryTree tree5(7);
    tree5.insert(4, std::vector<int> {0});
    tree5.insert(9, std::vector<int> {1});
    tree5.insert(1, std::vector<int> {0,0});
    tree5.insert(6, std::vector<int> {0,1});
    std::cout << "tree5: " << &tree5 << std::endl;

    BinaryTree tree6(5);
    tree6.insert(1, std::vector<int> {0});
    tree6.insert(8, std::vector<int> {1});
    tree6.insert(9, std::vector<int> {1,0});
    tree6.insert(12, std::vector<int> {1,1});
    std::cout << "tree6: " << &tree6 << std::endl;

    bool bin1 = tree3.isBinarySearch(tree3.getRoot());
    bool bin2 = tree4.isBinarySearch(tree4.getRoot());
    bool bin3 = tree5.isBinarySearch(tree5.getRoot());
    bool bin4 = tree6.isBinarySearch(tree6.getRoot());
    std::cout << bin1 << std::endl;
    std::cout << bin2 << std::endl;
    std::cout << bin3 << std::endl;
    std::cout << bin4 << std::endl;
    BinaryTree tree7(50);
    tree7.insert(20, std::vector<int> {0});
    tree7.insert(70, std::vector<int> {1});
    tree7.insert(10, std::vector<int> {0,0});
    tree7.insert(33, std::vector<int> {0,1});
    tree7.insert(60, std::vector<int> {1,0});
    tree7.insert(100, std::vector<int> {1,1});
    std::cout << "tree7: " << std::endl << &tree7 << std::endl;
    return 0;
}
