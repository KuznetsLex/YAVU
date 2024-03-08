#include "demo.h"

using namespace std;

int main(int argc, const char** argv) {
    Box box1(1,1,1,5,0);
    Box box2(3,3,3,3,3);
    Box box3(3,3,3,3,3);

    const int BOXES_SIZE = 3;
    Box* boxes = new Box[BOXES_SIZE];
    boxes[0] = box1;
    boxes[1] = box2;
    boxes[2] = box3;

    cout << sumBoxValue(boxes, BOXES_SIZE) << endl;
    cout << ifAllSizesCorrect(boxes, BOXES_SIZE, 3) << endl;
    cout << maxWeightOfBoxes(boxes, BOXES_SIZE, 9) << endl;
    cout << ifBoxesInlinable(boxes, BOXES_SIZE) << endl;
    cout << "Are boxes equal?" << endl;
    cout << box1;
    cout << (box1 == box2) << endl;
    cout << (box2 == box3) << endl;
    cout << (box1 == box3) << endl;

    Box box4;
    cin >> box4;
    cout << box4;

    BoxAndContainer::Box box5(1,1,1,1,1);
    BoxAndContainer::Container container1(10,10,10,10);
    container1.addBox(box5);
    box5.setValue(2);
    container1.boxesCount();
    container1.addBox(box5);
    container1.addBox(container1[0]);
    cout << container1.boxesCount() << endl;
    cout << container1.boxesSumWeight() << endl;
    cout << container1.boxesSumValue() << endl;
    cout << container1.getBoxByIndex(1) << endl;
    cout << container1[0] << endl;
    delete[] boxes;
    return 0;
}
