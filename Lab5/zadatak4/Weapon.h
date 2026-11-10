#pragma once      
#include <iostream>
using namespace std;
// header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>

class Weapon {
    // data memberi
private:
    string name;

public:
    // konstruktor (deklaracija; definicija je u Weapon.cpp)
    Weapon(const string& n);
};
