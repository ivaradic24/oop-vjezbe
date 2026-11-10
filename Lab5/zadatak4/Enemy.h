#pragma once
#include <string>
using namespace std;
// header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

class Enemy {
    // data memberi
private:
    string name;

public:
    // konstruktor (deklaracija; definicija je u Enemy.cpp)
    Enemy(const string& n);
};
