
#include <iostream>
using namespace std;

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int twice(int x) {
    return x * 2;
}

int main() {
    int brojevi[] = {1, 2, 3, 4, 5};
    int n = 5;

    my_transform(brojevi, n, twice);

    cout << "Nakon udvostrucavanja: ";
    for (int i = 0; i < n; i++)
        cout << brojevi[i] << " ";
    cout << endl;

    my_transform(brojevi, n, [](int x) {
        if (x % 2 == 0)
            return x / 2;
        else
            return x * 2;
    });

    cout << "Nakon druge transformacije: ";
    for (int i = 0; i < n; i++)
        cout << brojevi[i] << " ";
    cout << endl;

    int zbroj = 0;
    int umnozak = 1;

    auto izracunaj = [&](int x) {
        zbroj += x;
        umnozak *= x;
    };

    for (int i = 0; i < n; i++)
        izracunaj(brojevi[i]);

    cout << "Zbroj: " << zbroj << endl;
    cout << "Umnozak: " << umnozak << endl;

    int prag = 3;
    int s = 0;

    auto zbroji_vece = [prag, &s](int x) {
        if (x > prag)
            s += x;
    };

    for (int i = 0; i < n; i++)
        zbroji_vece(brojevi[i]);

    cout << "Zbroj elemenata vecih od praga: " << s << endl;

    return 0;
}
