#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"
#include "Player.h"
using namespace std;

class Game {
    // data memberi
private:
    string title;
    Level level;
    Player player;

public:
    Game(const string& title, const string& player_name);
    void print() const;      // naziv igre, zatim stanje igraca
};
