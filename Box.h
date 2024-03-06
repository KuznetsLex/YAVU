#ifndef OMSU_BOX_H
#define OMSU_BOX_H
#include <iostream>
struct Box {
    int length, width, height;
    double weight;
    int value;
    Box(int inLength, int inWidth, int inHeight,
        double inWeight,
        int inValue);
    Box();
    bool operator== (const Box &box) const;
};
bool ifAllSizesCorrect(Box* boxesArr, size_t size, int maxSize);
int sumBoxValue(Box* boxesArr, size_t size);
double maxWeightOfBoxes(Box* boxesArr, size_t size, int maxV);
bool ifBoxesInlinable(Box* boxesArr, size_t size);
std::ostream & operator << (std::ostream &out, const Box &box);
std::istream & operator >> (std::istream &in,  Box &box);
#endif //OMSU_BOX_H
