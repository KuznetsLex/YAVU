#ifndef LAB5_TREEELEM_H
#define LAB5_TREEELEM_H



class TreeElem {
public:
        int info;
        TreeElem* left;
        TreeElem* right;
        TreeElem(int theInfo,
                  TreeElem* theLeft = nullptr,
                  TreeElem* theRight = nullptr): info(theInfo), left(theLeft), right(theRight) {}
};



#endif //LAB5_TREEELEM_H
