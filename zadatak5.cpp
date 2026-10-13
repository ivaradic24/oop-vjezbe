
#include <iostream>
#include <cmath>

struct Point {
    double x{};
    double y{};
};

void move_by_ptr(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double dist_ptr(const Point* a, const Point* b) {
    double dx{a->x - b->x};
    double dy{a->y - b->y};

    return std::sqrt(dx * dx + dy * dy);
}



void move_by_ref(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist_ref(const Point& a, const Point& b) {
    double dx{a.x - b.x};
    double dy{a.y - b.y};

    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1{1.0, 2.0};
    Point p2{4.0, 6.0};

    move_by_ptr(&p1, 2.0, 1.0);

    std::cout << "p1 nakon pomaka pointerom: "
              << p1.x << ", " << p1.y << '\n';

    std::cout << "Udaljenost (pointeri): "
              << dist_ptr(&p1, &p2) << '\n';

    move_by_ref(p1, -1.0, 0.0);

    std::cout << "p1 nakon pomaka referencom: "
              << p1.x << ", " << p1.y << '\n';

    std::cout << "Udaljenost (reference): "
              << dist_ref(p1, p2) << '\n';

    Point points[5] = {
        {3.0, 4.0},
        {1.0, 1.0},
        {-2.0, 1.0},
        {0.5, 0.5},
        {4.0, -1.0}
    };

    int indeksNajblize{0};

    for (int i{1}; i < 5; i++) {
        if (dist_ref(points[i], Point{0.0, 0.0}) <
            dist_ref(points[indeksNajblize], Point{0.0, 0.0})) {
            indeksNajblize = i;
        }
    }

    std::cout << "Tocka najbliža ishodištu: ("
              << points[indeksNajblize].x << ", "
              << points[indeksNajblize].y << ")\n";

    return 0;
}
