#include <iostream>
#include <string>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b) {
    return a > b ? a : b;
}

template <typename T>
T my_max_template(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;

    cout << a << " " << b << " " << c << endl;

    cout << my_max(3, 5) << endl;

    int i = 3;
    cout << MAX(++i, 2) << endl;

    i = 3;
    cout << my_max(++i, 2) << endl;

    cout << my_max_template(3, 5) << endl;
    cout << my_max_template(3.2, 5.7) << endl;
    cout << my_max_template('a', 'z') << endl;
    cout << my_max_template(string("ana"), string("iva")) << endl;

    return 0;
}