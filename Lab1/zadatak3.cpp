
#include <iostream>
#include <cstdlib>

int& find_max(int arr[], int n) {
    int indeksMax{0};

    for (int i{1}; i < n; i++) {
        if (arr[i] > arr[indeksMax]) {
            indeksMax = i;
        }
    }

    return arr[indeksMax];
}

int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n{6};

    std::cout << "Pocetni niz: ";

    for (int broj : numbers) {
        std::cout << broj << ' ';
    }

    std::cout << '\n';

    for (int& broj : numbers) {
        if (broj < 0) {
            broj = std::abs(broj);
        }
    }

    std::cout << "Nakon zamjene negativnih: ";

    for (int broj : numbers) {
        std::cout << broj << ' ';
    }

    std::cout << '\n';

    find_max(numbers, n) = 0;

    std::cout << "Nakon postavljanja maksimuma na 0: ";

    for (int broj : numbers) {
        std::cout << broj << ' ';
    }

    std::cout << '\n';

    return 0;
}
