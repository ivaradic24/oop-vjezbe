// Vjezba 7, zadatak 1: napisite strukturu Vec2 i operatore iznad main.

#include <iostream>
using namespace std;

// ovdje napisite Vec2 i operatore

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

int main()
{
    Vec2 player{2, 3};
    Vec2 right{1, 0};
    Vec2 down{0, 1};

    player += right;
    std::cout << player << '\n';
    player += 2 * down;
    std::cout << player << '\n';
    Vec2 target = player + right * 3 - down;
    std::cout << target << '\n';

    Vec2 enemy{6, 4};
    std::cout << (target == enemy) << ' ' << (player != enemy) << '\n';
    std::cout << player << " -> " << target << '\n';
    return 0;
}

/*
Ocekivani ispis:

    (3, 3)
    (3, 5)
    (6, 4)
    1 1
    (3, 5) -> (6, 4)
*/
