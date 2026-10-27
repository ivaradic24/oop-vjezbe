
#include <iostream>

namespace geo {
    constexpr double PI{3.141592653589793};

    double area(double r) {
        return PI * r * r;
    }

    double area(double a, double b) {
        return a * b;
    }

    int area(int a) {
        return a * a;
    }
}

void print_line(char c = '-', int length = 30) {
    for (int i{0}; i < length; i++) {
        std::cout << c;
    }

    std::cout << '\n';
}

int main() {
    std::cout << "area(5): " << geo::area(5) << '\n';
    std::cout << "area(5.0): " << geo::area(5.0) << '\n';
    std::cout << "area(2, 3): " << geo::area(2, 3) << '\n';
    std::cout << "area('A'): " << geo::area('A') << '\n';

    print_line();

    std::cout << "Prilagođena linija:" << '\n';
    print_line('*', 15);

    return 0;
}
