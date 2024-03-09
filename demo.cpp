#include "demo.h"

using namespace std;

int main(int argc, const char** argv) {
    Box box1(1,1,1,5,0);
    Box box2(3,3,3,3,3);
    Box box3(3,3,3,3,3);

    cout << box1;
    cout << box2;
    cout << box3;

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
    cout << (box1 == box2) << endl;
    cout << (box2 == box3) << endl;
    cout << (box1 == box3) << endl;

    Box box4;
    cout << "Create new box: " << endl;
    cin >> box4;
    cout << box4;

    BoxAndContainer::Box box5(1,1,1,1,1);
    cout << box5 << endl;
    BoxAndContainer::Container container1(10,10,10,10);
    cout << container1 << endl;
    cout << "box1 index: " << container1.addBox(box5) << endl;
    box5.setValue(2);
    cout << "boxesCount: " << container1.boxesCount() << endl;
    cout << "box2 index: " << container1.addBox(box5) << endl;
    container1.deleteBoxByIndex(1);
    cout << "boxesCount: " << container1.boxesCount() << endl;
    cout << "box3 index: " << container1.addBox(container1[0]) << endl;
    cout << "boxesCount: " << container1.boxesCount() << endl;
    cout << "boxesSumWeight: " << container1.boxesSumWeight() << endl;
    cout << "boxesSumValue: " << container1.boxesSumValue() << endl;
    cout << "getBoxByIndex: " << container1.getBoxByIndex(1) << endl;
    cout << "container1[0]: " << container1[0] << endl;
    cout << "container1[1]: " << container1[1] << endl;
    delete[] boxes;
    return 0;
}
