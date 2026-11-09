#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input_vector() {
    vector<int> v;
    int x;

    cout << "unesite brojeve (0 za kraj): ";
    while (cin >> x && x != 0) {
        v.push_back(x);
    }
    return v;
}

int main() {
    vector<int> v = input_vector();

    int k;
    cout << "k: ";
    cin >> k;

    int negativnih = count_if(v.begin(), v.end(),
        [](int x) { return x < 0; });

    cout << "negativnih: " << negativnih << endl;

    auto prvi = find_if(v.begin(), v.end(),
        [k](int x) { return x % k == 0; });

    if (prvi != v.end()) {
        cout << "prvi visekratnik od " << k << ": "
             << *prvi << " (pozicija "
             << distance(v.begin(), prvi) << ")" << endl;
    }
    else {
        cout << "nema visekratnika." << endl;
    }

    if (!v.empty()) {
        auto [min_it, max_it] =
            minmax_element(v.begin(), v.end());

        cout << "min " << *min_it
             << " (pozicija " << distance(v.begin(), min_it)
             << "), max " << *max_it
             << " (pozicija " << distance(v.begin(), max_it)
             << ")" << endl;
    }

    v.erase(remove_if(v.begin(), v.end(),
        [k](int x) { return x % k == 0; }), v.end());

    cout << "bez visekratnika: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}