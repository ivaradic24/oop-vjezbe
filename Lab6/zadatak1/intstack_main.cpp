// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>

// ovdje napisite klasu IntStack

class IntStack {
private:
    int* data;
    int count;
    int cap;

public:
    IntStack(int capacity = 2) {
        cap = capacity;
        count = 0;
        data = new int[cap];
    }

    ~IntStack() {
        delete[] data;
    }

    IntStack(const IntStack& other) {
        cap = other.cap;
        count = other.count;

        data = new int[cap];

        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    }

    void push(int x) {
        if (count == cap) {
            cap *= 2;

            int* novi = new int[cap];

            for (int i = 0; i < count; i++) {
                novi[i] = data[i];
            }

            delete[] data;
            data = novi;
        }

        data[count] = x;
        count++;
    }

    void pop() {
        if (count > 0) {
            count--;
        }
    }

    int top() const {
        return data[count - 1];
    }

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    int capacity() const {
        return cap;
    }
};


int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    5 8 50
    50 99
    50 40 30 20 10
*/
