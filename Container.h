#ifndef LAB0_CONTAINER_H
#define LAB0_CONTAINER_H
#include <iostream>
#include "BoxClass.h"
namespace BoxAndContainer {
    class Container
            {
    private:
        std::vector<BoxAndContainer::Box> boxes;
        int length, width, height;
        double maxWeight;
    public:
        Container(int length, int width, int height, double maxWeight);
        const std::vector <BoxAndContainer::Box> &getBoxes() const;
        void setBoxes(const std::vector <BoxAndContainer::Box> &boxes);
        int getLength() const;
        void setLength(int length);
        int getWidth() const;
        void setWidth(int width);
        int getHeight() const;
        void setHeight(int height);
        double getMaxWeight() const;
        void setMaxWeight(double maxWeight);
        unsigned int boxesCount();
        double boxesSumWeight();
        double boxesSumValue();
        Box getBoxByIndex(int i);
        unsigned long addBox(Box box);
        void deleteBoxByIndex(int i);

        class ContainerOverweightException: public std::exception {
            const char* message;
        public:
            ContainerOverweightException(const char* theMessage): message(theMessage) { } const char* what() const noexcept { return message; }
        };

//        friend std::ostream &operator<<(std::ostream &out, const Container &container);
//        friend std::istream &operator>>(std::istream &in, Container &container);
//        Box operator[](const Container &container, int i) const;
        Box operator[](int i) const;
    };

    std::istream & operator >> (std::istream &in,  Container &container);
    std::ostream & operator << (std::ostream &out, const Container &container);
}
#endif //LAB0_CONTAINER_H