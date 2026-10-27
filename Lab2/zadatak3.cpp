#include <iostream>
using namespace std;

template <typename T>
inline bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a > b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (!cmp(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int brojevi[] = {5, 2, 8, 1, 4};
    double decimalni[] = {3.5, 1.2, 4.8, 2.1};
    char slova[] = {'d', 'a', 'c', 'b'};

    my_sort(brojevi, 5, ascending<int>);
    my_sort(decimalni, 4, ascending<double>);
    my_sort(slova, 4, descending<char>);

    for (int x : brojevi)
        cout << x << " ";

    cout << endl;

    for (double x : decimalni)
        cout << x << " ";

    cout << endl;

    for (char x : slova)
        cout << x << " ";

    cout << endl;

    return 0;
}