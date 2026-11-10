#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"
using namespace std;

class Level {
    // data memberi
private:
    vector<Enemy> enemies;
    vector<Weapon> weapons;

public:
    // konstruktor
    Level();
    
    int enemy_count() const;
    int weapon_count() const;
};
