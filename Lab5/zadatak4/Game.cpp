#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(const string& title, const string& player_name)
    : title(title), level(), player(player_name, &level) {
}

void Game::print() const {
    cout << title << endl;
    player.print();
}

// definicije konstruktora i metode print
