// Vjezba 7, zadatak 4: napisite klasu Inventory iznad funkcije show.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ovdje napisite klasu Inventory

class Inventory {
    vector<string> items;
    size_t capacity;

public:
    Inventory(size_t maxItems)
        : capacity(maxItems) {}

    Inventory& operator+=(const string& item) {
        if (items.size() < capacity) {
            items.push_back(item);
        }

        return *this;
    }

    std::string& operator[](size_t index) {
        return items[index];
    }

    const string& operator[](size_t index) const {
        return items[index];
    }

    std::size_t size() const {
        return items.size();
    }

    explicit operator bool() const {
        return !items.empty();
    }
};

void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/
