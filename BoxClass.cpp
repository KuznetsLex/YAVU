#include "BoxClass.h"
#include <iostream>

BoxAndContainer::Box::Box() : length(0), width(0), height(0), weight(0), value(0) {}

BoxAndContainer::Box::Box(int length, int width, int height, double weight, int value) : length(length),
                                                                                         width(width),
                                                                                         height(height),
                                                                                         weight(weight),
                                                                                         value(value) {
    std::cout << "STATUS: Box class initialized correctly" << std::endl;
}

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

std::ostream &BoxAndContainer::operator<<(std::ostream &out, const BoxAndContainer::Box &box) {
    out << "Height: " << box.getHeight() << ", width:" << box.getWidth() << ", length: " << box.getLength()
        << ", weight: " << box.getWeight() << ", value: " << box.getValue() << std::endl;
    return out;
}

std::istream &BoxAndContainer::operator>>(std::istream &in, BoxAndContainer::Box &box) {
    int height, width, length, value;
    double weight;
    std::cout << "height: ";
    in >> height;
    box.setHeight(height);
    std::cout << "width: ";
    in >> width;
    box.setWidth(width);
    std::cout << "length: ";
    in >> length;
    box.setLength(length);
    std::cout << "Weight: ";
    in >> weight;
    box.setWeight(weight);
    std::cout << "Value: ";
    in >> value;
    box.setValue(value);
    return in;
}
