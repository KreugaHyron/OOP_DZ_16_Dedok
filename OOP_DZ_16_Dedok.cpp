#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;
class Point {
public:
    int x;
    int y;
    Point() : x(0), y(0) {} 
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};
template <typename T>
class DynArray {
    T* arr;
    int size;
public:
    DynArray(int sizeP)
        : arr{ new T[sizeP] {} }, size{ sizeP } {
        cout << "DynArr constructed for " << size
            << " elements, for " << this << '\n';
    }
    DynArray() : DynArray(5) {}
    DynArray(const DynArray& object)
        : arr{ new T[object.size] }, size{ object.size } {
        for (int i = 0; i < size; ++i) {
            arr[i] = object.arr[i];
        }
        cout << "DynArr copy constructed for "
            << size << " elements, for " << this
            << '\n';
    }
    T getElem(int idx) { return arr[idx]; }
    void setElem(int idx, T val) { arr[idx] = val; }
    void print();
    void randomize();
    T sum();
    int getSize() const { return size; }
    ~DynArray() {
        delete[] arr;
        cout << "DynArr destructed for"
            << size << " elements, for"
            << this << '\n';
    }
    DynArray<T> operator+(const DynArray<T>& other) const {
        DynArray<T> result(size);
        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }
};
template <typename T>
void DynArray<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
template <typename T>
void DynArray<T>::randomize() {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
}
template <typename T>
T DynArray<T>::sum() {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    DynArray<int> intArray{ 5 };
    intArray.randomize();
    cout << "Sum of intArray elements: " << intArray.sum() << endl;

    DynArray<double> doubleArray{ 5 };
    doubleArray.randomize();
    cout << "Sum of doubleArray elements: " << doubleArray.sum() << endl;

    DynArray<char> charArray{ 5 };
    charArray.randomize();
    cout << "Sum of charArray elements: " << (int)charArray.sum() << endl;

    DynArray<Point> pointArray{ 3 };
    pointArray.setElem(0, Point(1, 2));
    pointArray.setElem(1, Point(3, 4));
    pointArray.setElem(2, Point(5, 6));

    Point sumOfPoints;
    for (int i = 0; i < pointArray.getSize(); ++i) {
        sumOfPoints = sumOfPoints + pointArray.getElem(i);
    }
    cout << "Sum of pointArray elements (x coordinates): " << sumOfPoints.x << endl;
    cout << "Sum of pointArray elements (y coordinates): " << sumOfPoints.y << endl;

    return 0;
}