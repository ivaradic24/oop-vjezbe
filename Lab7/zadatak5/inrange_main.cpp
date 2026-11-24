// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ovdje kopirajte Vec2 i operatore iz zadatka 1

struct Vec2 {
    int x;
    int y;

    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

Vec2 operator+(Vec2 a, const Vec2& b) {
    a += b;
    return a;
}

Vec2 operator-(Vec2 a, const Vec2& b) {
    a -= b;
    return a;
}

Vec2 operator*(Vec2 v, int n) {
    return {v.x * n, v.y * n};
}

Vec2 operator*(int n, Vec2 v) {
    return v * n;
}

bool operator==(const Vec2& a, const Vec2& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b) {
    return !(a == b);
}

ostream& operator<<(ostream& out, const Vec2& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

// ovdje napisite struct Enemy

struct Enemy {
    string name;
    Vec2 position;
};

// ovdje napisite klasu InRange

class InRange {
    Vec2 center;
    int range;

public:
    InRange(Vec2 c, int r)
        : center(c), range(r) {}

    bool operator()(const Enemy& enemy) const {
        int dx = enemy.position.x - center.x;
        int dy = enemy.position.y - center.y;

        return dx * dx + dy * dy <= range * range;
    }
};

int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    /* ovdje pozovite count_if s funkcijskim objektom */
    int range = 2;
    int count1 = count_if(
        enemies.begin(), enemies.end(), near
    );
    cout << count1 << '\n';

    /* ovdje pozovite count_if s lambdom */
    int count2 = count_if(
        enemies.begin(), enemies.end(),
        [player, range](const Enemy& enemy) {
            int dx = enemy.position.x - player.x;
            int dy = enemy.position.y - player.y;

            return dx * dx + dy * dy <= range * range;
        }
    );

    cout << count2 << '\n';

    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/
