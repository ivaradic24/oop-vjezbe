#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(const std::string& n, Level* l)
    : name(n), level(l) {
}

void Player::print() const {
    cout << "Igrac: " << name << endl;

    cout << "Level: neprijatelja "
        << level->enemy_count()
        << ", oruzja "
        << level->weapon_count()
        << endl;
}

// definicije konstruktora i metode print
