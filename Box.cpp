#include "Box.h"

using std::cin;
using std::cout;
using std::endl;

Box::Box(int inLength, int inWidth, int inHeight,
        double inWeight,
        int inValue): length(inLength), width(inWidth), height(inHeight), weight(inWeight), value(inValue)
    {
        assert((inWeight > 0) && "ERROR: Wrong input! Weight should be positive.");
        assert((inLength > 0) && "ERROR: Wrong input! Length should be positive.");
        assert((inWidth > 0) && "ERROR: Wrong input! Width should be positive.");
        assert((inHeight > 0) && "ERROR: Wrong input! Height should be positive.");
        assert((inValue >= 0) && "ERROR: Wrong input! Value shouldn't be negative.");
        std::cout << "STATUS: Box initialized correctly" << std::endl;
    }

Box::Box(): length(0), width(0), height(0), weight(0), value(0){}

// Вход: boxesArr - массив элементов типа Box; maxSize - неотрицательный размер, совпадающий с размером входного массива
// Выход: суммарная стоимость содержимого коробок в массиве
int sumBoxValue(Box* boxesArr, size_t size)
{
    cout << "STATUS: sumBoxValue function invoked..." << endl;
    assert((boxesArr != nullptr) && "ERROR: Received array is null!");
    assert((size >= 0) && "ERROR: Wrong input! Size of array should not be negative");

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += boxesArr[i].value;
    }
    return sum;
}

// Вход: boxesArr - массив элементов типа Box; maxSize - неотрицательный размер, совпадающий с размером входного массива
// Выход: true, если сумма длины, ширины и высоты всех коробок массива boxesArr не превосходит заданного значения maxSize, false иначе
bool ifAllSizesCorrect(Box* boxesArr, size_t size, int maxSize)
{
    cout << "STATUS: ifAllSizesCorrect function invoked..." << endl;
    assert((boxesArr != nullptr) && "ERROR: Received array is null!");
    assert((size >= 0) && "ERROR: Wrong input! Size of array should not be negative");
    assert((maxSize > 0) && "ERROR: Wrong input! maxSize should be positive");

    for (int i = 0; i < size; i++)
    {
        if (boxesArr[i].height + boxesArr[i].length + boxesArr[i].width > maxSize) { return false; }
    }
    return true;
}

// Вход: boxesArr - массив элементов типа Box; maxSize - неотрицательный размер, совпадающий с размером входного массива; maxV - максимальное значение объема сравнениваемых коробок
// Выход: максимальный вес коробок, объем которых не больше параметра maxV.
double maxWeightOfBoxes(Box* boxesArr, size_t size, int maxV)
{
    cout << "STATUS: maxWeightOfBoxes function invoked..." << endl;
    assert((boxesArr != nullptr) && "ERROR: Received array is null!");
    assert((size >= 0) && "ERROR: Wrong input! Size of array should not be negative");
    assert((maxV > 0) && "ERROR: Wrong input! maxV should be positive");

    double maxWeight = 0;
    for (int i = 0; i < size; i++)
    {
        if (boxesArr[i].height * boxesArr[i].length * boxesArr[i].width <= maxV)
        {
            if (boxesArr[i].weight > maxWeight)
            {
                maxWeight = boxesArr[i].weight;
            }
        }
    }
    return maxWeight;
}

// Вход: boxesArr - массив элементов типа Box; maxSize - неотрицательный размер, совпадающий с размером входного массива
// Выход: входной массив boxesArr сортируется по возрастанию объема коробок
void bubbleSortBoxesByValueAscending(Box* boxesArr, size_t size)
{
    while(size--)
    {
        bool swapped = false;
        for(int i = 0; i < size; i++)
        {

            if(boxesArr[i].length * boxesArr[i].width * boxesArr[i].height  > boxesArr[i+1].length * boxesArr[i+1].width * boxesArr[i+1].height)
            {
                std::swap(boxesArr[i], boxesArr[i + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

// Вход: boxesArr - массив элементов типа Box; maxSize - неотрицательный размер, совпадающий с размером входного массива
// Выход: true, если все коробки можно вложить друг в друга, false иначе. Побочный эффект: входной массив boxesArr сортируется по возрастанию объема коробок
bool ifBoxesInlinable(Box* boxesArr, size_t size)
{
    cout << "STATUS: areBoxesInlinable function invoked..." << endl;
    assert((boxesArr != nullptr) && "ERROR: Received array is null!");
    assert((size >= 0) && "ERROR: Wrong input! Size of array should not be negative");

    bubbleSortBoxesByValueAscending(boxesArr, size);
    for (int i = 1; i < size; i++)
    {
        if (
                boxesArr[i-1].height > boxesArr[i].height ||
                boxesArr[i-1].length > boxesArr[i].length ||
                boxesArr[i-1].width > boxesArr[i].width
                )
        {
            return false;
        }
    }
    return true;
}

bool Box::operator== (const Box &box) const
{
    return (length == box.length && width == box.width && height == box.height && value == box.value);
}

std::ostream & operator << (std::ostream &out, const Box &box)
{
    out << "Height: " << box.height << ", width:" << box.width << ", length: " << box.length << ", weight: " << box.weight << ", value: " << box.value << endl;
    return out;
}

std::istream & operator >> (std::istream &in,  Box &box)
{
    cout << "Height: ";
    in >> box.height;
    assert((box.height > 0) && "ERROR: height should be positive");
    cout << "Width: ";
    in >> box.width;
    assert((box.width > 0) && "ERROR: width should be positive");
    cout << "Length: ";
    in >> box.length;
    assert((box.length > 0) && "ERROR: length should be positive");
    cout << "Weight: ";
    in >> box.weight;
    assert((box.weight > 0) && "ERROR: weight should be positive");
    cout << "Value: ";
    in >> box.value;
    assert((box.value >= 0) && "ERROR: value should be nonnegative");
    return in;
}


