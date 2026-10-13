#include <iostream>

int main(){
    int a{}, b{};

    std::cout << "Unesi dva cijela broja: ";
    std::cin >> a >> b;

    int zbroj{a+b};
    double sredina{(a+b) / 2.0};
    bool manje{a<b};

    std::cout << "zbroj: " << zbroj << '\n';
    std::cout << "aritmeticka sredina: " << sredina << '\n';
    std::cout << "je li a<b?" << std::boolalpha << manje << '\n';

    return 0;
}