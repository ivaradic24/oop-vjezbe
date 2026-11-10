#include "Level.h"
using namespace std;

Level::Level()
    : enemies{Enemy("Goblin")}, weapons{}{

    }

int Level::enemy_count() const {
    return enemies.size();
}

int Level::weapon_count() const {
    return weapons.size();
}

// definicije konstruktora i metoda
