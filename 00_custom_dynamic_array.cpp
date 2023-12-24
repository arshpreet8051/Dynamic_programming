#include<iostream>

using namespace std;

class Vector {
public:
    int size;
    int capacity;
    int* arr;

    Vector() {
        this->size = 1;
        this->capacity = 0;
        arr = new int[size];
    }

    Vector(int size) {
        this->size = size;
        this->capacity = 0;
        arr = new int[size];
    }

    ~Vector() {
        delete[] arr;
    }

    bool push(int x) {
        if (this->capacity == this->size) {
            int* temp = new int[size * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            this->size *= 2;
            delete[] arr; // Release old memory
            arr = temp;
        }
        arr[capacity++] = x;
        return true;
    }

    int pop() {
        if (capacity <= 0) {
            return -1;
        }
        return arr[--capacity];
    }
};

int main() {
    Vector v = Vector();
    cout << v.push(1) << " " << v.size << " " << v.capacity << endl;
    cout << v.push(2) << " " << v.size << " " << v.capacity << endl;
    cout << v.push(3) << " " << v.size << " " << v.capacity<<endl;
    cout << v.push(3) << " " << v.size << " " << v.capacity<<endl;

    return 0;
}
