// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.

#include <cassert>
#include <iostream>
#include <string>
using namespace std;

// ovdje napisite klasu RecentlyPlayed

class RecentlyPlayed {
private:
    std::string* data;
    int cap;
    int count;
    int next;

public:
    RecentlyPlayed(int capacity) {
        assert(capacity > 0);

        cap = capacity;
        count = 0;
        next = 0;

        data = new string[cap];
    }

    ~RecentlyPlayed() {
        delete[] data;
    }

    RecentlyPlayed(const RecentlyPlayed& other) {
        cap = other.cap;
        count = other.count;
        next = other.next;

        data = new string[cap];

        for (int i = 0; i < cap; i++) {
            data[i] = other.data[i];
        }
    }

    void play(const string& title) {
        data[next] = title;

        next = (next + 1) % cap;

        if (count < cap) {
            count++;
        }
    }

    int size() const {
        return count;
    }

    int capacity() const {
        return cap;
    }

    string get(int i) const {
        assert(i >= 0 && i < count);

        int index = (next - 1 - i + cap) % cap;

        return data[index];
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            if (i > 0) {
                cout << ", ";
            }

            cout << get(i);
        }

        cout << '\n';
    }
};


int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
