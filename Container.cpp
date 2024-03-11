#include "Container.h"
#include "BoxClass.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::vector;

namespace BoxAndContainer {
    BoxAndContainer::Container::Container(int length, int width, int height, double maxWeight) : length(length),
                                                                                                 width(width),
                                                                                                 height(height),
                                                                                                 maxWeight(maxWeight) {
        std::cout << "STATUS: Container initialized correctly" << std::endl;
        assert((length > 0) && "ERROR: Wrong input! Length should be positive.");
        assert((width > 0) && "ERROR: Wrong input! Width should be positive.");
        assert((height > 0) && "ERROR: Wrong input! Height should be positive.");
        assert((maxWeight >= 0) && "ERROR: Wrong input! maxWeight should be positive.");
    }

    const vector <BoxAndContainer::Box> &BoxAndContainer::Container::getBoxes() const {
        return boxes;
    }

    void BoxAndContainer::Container::setBoxes(const vector <Box> &boxes_) {
        assert((!boxes.empty()) && "ERROR: array is empty");
        Container::boxes = boxes_;
    }

    int BoxAndContainer::Container::getLength() const {
        return length;
    }

    void BoxAndContainer::Container::setLength(int length_) {
        assert((length > 0) && "ERROR: length should be positive");
        Container::length = length_;
    }

    int BoxAndContainer::Container::getWidth() const {
        return width;
    }

    void BoxAndContainer::Container::setWidth(int width_) {
        assert((width > 0) && "ERROR: width should be positive");
        Container::width = width_;
    }

    int BoxAndContainer::Container::getHeight() const {
        return height;
    }

    void BoxAndContainer::Container::setHeight(int height_) {
        assert((height > 0) && "ERROR: height should be positive");
        Container::height = height_;
    }

    double BoxAndContainer::Container::getMaxWeight() const {
        return maxWeight;
    }

    void BoxAndContainer::Container::setMaxWeight(double maxWeight_) {
        assert((maxWeight > 0) && "ERROR: maxWeight should be positive");
        Container::maxWeight = maxWeight_;
    }

    unsigned int BoxAndContainer::Container::boxesCount() {
        return boxes.size();
    }

    double BoxAndContainer::Container::boxesSumWeight() {
        double boxesSumWeight = 0;
        for (Box box: boxes) {
            boxesSumWeight += box.getWeight();
        }
        return boxesSumWeight;
    }

    double BoxAndContainer::Container::boxesSumValue() {
        int boxesSumValue = 0;
        for (Box box: boxes) {
            boxesSumValue += box.getValue();
        }
        return boxesSumValue;
    }

    BoxAndContainer::Box BoxAndContainer::Container::getBoxByIndex(int i) {
        return boxes[i];
    }

    unsigned long BoxAndContainer::Container::addBox(BoxAndContainer::Box box) {
        cout << "STATUS: addBox function invoked..." << endl;
        if (boxesSumWeight() + box.getWeight() > maxWeight) {
            throw ContainerOverweightException("Overweight exception: Box is too heavy to be added to the container!");
        }
        boxes.push_back(box);
        return boxes.size() - 1;
    }

    void BoxAndContainer::Container::deleteBoxByIndex(int i) {
        assert((i >= 0) && "ERROR: Wrong input! Index should be nonnegative.");
        boxes.erase(boxes.begin()+i);
    }

    BoxAndContainer::Box BoxAndContainer::Container::operator[](int i) const {
        assert((i >= 0) && "ERROR: Wrong input! Index should be nonnegative.");
        return boxes[i];
    }

    ostream &BoxAndContainer::operator<<(ostream &out, const BoxAndContainer::Container &container) {
        out << "Height: " << container.getHeight() << ", width:" << container.getWidth() << ", length: "
            << container.getLength() << ", maxWeight:" << container.getMaxWeight() << endl;
        return out;
    }

    istream &BoxAndContainer::operator>>(istream &in, BoxAndContainer::Container &container) {
        int height, width, length, maxWeight;
        cout << "height: ";
        in >> height;
        container.setHeight(height);
        cout << "width: ";
        in >> width;
        container.setWidth(width);
        cout << "length: ";
        in >> length;
        container.setLength(length);
        cout << "maxWeight: ";
        in >> maxWeight;
        container.setMaxWeight(maxWeight);
        return in;
    }
}