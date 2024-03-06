#ifndef LAB0_BOXCLASS_H
#define LAB0_BOXCLASS_H
#include <iostream>
namespace BoxAndContainer{
    class Box
            {
    private:
        int length, width, height;
        double weight;
        int value;
    public:
        Box();
        Box(int length, int width, int height, double weight, int value);
        int getLength() const;
        void setLength(int length);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);
        double getWeight() const;
        void setWeight(double weight);
        int getValue() const;
        void setValue(int value);
    };
}
#endif //LAB0_BOXCLASS_H
