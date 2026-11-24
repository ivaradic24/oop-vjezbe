// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>
using namespace std;

// ovdje napisite klasu IntStack

class IntStack {
    int* data;
    int capacity;
    int count;

public:
    IntStack() : data(nullptr), capacity(0), count(0) {}

    ~IntStack() {
        delete[] data;
    }

    void push(int value) {
        if (count == capacity) {
            int newCapacity = capacity == 0 ? 2 : capacity * 2;

            int* newData = new int[newCapacity];

            for (int i = 0; i < count; ++i)
                newData[i] = data[i];

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        data[count++] = value;
    }

    int top() const {
        return data[count - 1];
    }

    int size() const {
        return count;
    }


    IntStack(const IntStack& other)
        : data(new int[other.capacity]),
          capacity(other.capacity),
          count(other.count) {

        for (int i = 0; i < count; ++i)
            data[i] = other.data[i];

        cout << "copy konstruktor\n";
    }


    IntStack& operator=(const IntStack& other) {
        cout << "copy assignment\n";

        if (this == &other)
            return *this;

        int* newData = new int[other.capacity];

        for (int i = 0; i < other.count; ++i)
            newData[i] = other.data[i];

        delete[] data;

        data = newData;
        capacity = other.capacity;
        count = other.count;

        return *this;
    }


    IntStack(IntStack&& other) noexcept
        : data(other.data),
          capacity(other.capacity),
          count(other.count) {

        other.data = nullptr;
        other.capacity = 0;
        other.count = 0;

        cout << "move konstruktor\n";
    }


    IntStack& operator=(IntStack&& other) noexcept {
        cout << "move assignment\n";

        if (this == &other)
            return *this;

        delete[] data;

        data = other.data;
        capacity = other.capacity;
        count = other.count;

        other.data = nullptr;
        other.capacity = 0;
        other.count = 0;

        return *this;
    }
};

int main()
{
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/
