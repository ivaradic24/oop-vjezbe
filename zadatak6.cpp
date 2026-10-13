
#include <iostream>
#include <numeric>

struct Fraction {
    int numerator{};
    int denominator{1};

    void reduce() {
        int nzd{std::gcd(numerator, denominator)};

        numerator /= nzd;
        denominator /= nzd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    void print() const {
        std::cout << numerator << '/' << denominator;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction result{
        a.numerator * b.denominator + b.numerator * a.denominator,
        a.denominator * b.denominator
    };

    result.reduce();

    return result;
}

int main() {
    Fraction f1{1, 2};
    Fraction f2{1, 4};

    std::cout << "Prvi razlomak: ";
    f1.print();
    std::cout << '\n';

    std::cout << "Decimalna vrijednost: "
              << f1.value() << '\n';

    Fraction zbroj{sum(f1, f2)};

    std::cout << "Zbroj razlomaka: ";
    zbroj.print();
    std::cout << '\n';

    std::cout << "Decimalna vrijednost zbroja: "
              << zbroj.value() << '\n';

    return 0;
}
