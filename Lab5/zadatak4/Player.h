#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"
using namespace std;

class Player {
    // data memberi
private:
    string name;
    Level* level;

public:
    // konstruktor
    Player(const string& n, Level* l);
    void print() const;      // ime i stanje levela u kojem je igrac
};
