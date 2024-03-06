#include "BoxClass.h"

BoxAndContainer::Box::Box() : length(0), width(0), height(0), weight(0), value(0) {}

BoxAndContainer::Box::Box(int length, int width, int height, double weight, int value) : length(length), width(width), height(height),
                                                                   weight(weight), value(value) {}

int BoxAndContainer::Box::getLength() const {
    return length;
}

void BoxAndContainer::Box::setLength(int length_) {
    assert((length > 0) && "ERROR: length should be positive");
    length = length_;
}

int BoxAndContainer::Box::getWidth() const {
    return width;
}

void BoxAndContainer::Box::setWidth(int width_) {
    assert((width > 0) && "ERROR: width should be positive");
    width = width_;
}

int BoxAndContainer::Box::getHeight() const {
    return height;
}

void BoxAndContainer::Box::setHeight(int height_) {
    assert((height > 0) && "ERROR: height should be positive");
    height = height_;
}

double BoxAndContainer::Box::getWeight() const {
    return weight;
}

void BoxAndContainer::Box::setWeight(double weight_) {
    assert((weight > 0) && "ERROR: weight should be positive");
    weight = weight_;
}

int BoxAndContainer::Box::getValue() const {
    return value;
}

void BoxAndContainer::Box::setValue(int value_) {
    assert((value > 0) && "ERROR: value should be positive");
    value = value_;
}


