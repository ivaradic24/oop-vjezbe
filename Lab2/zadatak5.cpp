#include <iostream>
using namespace std;

inline double add(double a, double b){
    return a + b;
}

inline double subtract(double a, double b){
    return a - b;
}

inline double multiply(double a, double b){
    return a * b;
}

inline double divide (double a, double b){
    return a / b;
}

int main(){
    double a, b;
    int operacija;

    double (*funckije[4])(double, double) = {add, subtract, multiply, divide};

    cout << "Unesite dva broja: ";
    cin >> a >> b;

    cout << "Unesite operaciju (0 - zbrajanje, 1 - oduzimanje, 2 - mnozenje, 3 - djeljenje): ";
    cin >> operacija;

    if(operacija < 0 || operacija > 3){
        cout << "Neispravna operacija!" << endl;
    } else if (operacija == 3 && b == 0) {
        cout << "Djeljenje s nulom nije dozvoljeno!" << endl;
    } else {
        cout << "Rezultat: " << funckije[operacija](a, b) << endl;
    }

    return 0;
}