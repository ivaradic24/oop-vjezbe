#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;

    cout << "broj dana: ";
    cin >> n;

    vector<double> temperature(n);

    for (int i=0; i<n; i++){
        cin >> temperature[i];
    }

    vector<double> promjene;
    promjene.reserve(n-1);

    for (auto it=temperature.begin()+1;
        it != temperature.end(); ++it){
            promjene.push_back(*it - *(it-1));
    }

    cout << "promjene: ";
    for (double p : promjene){
        cout << p << " ";
    }

    cout << endl;

    if (n>0){
        temperature.resize(7, temperature.back());
    }

    cout << "izvjestaj: ";
    for (double t : temperature){
        cout << t << " ";
    }

    cout << endl;

    vector<int> a(5);
    vector<int> b{5};

    cout << "a ima elemenata: " << a.size() << endl;
    cout << "b ima eleemenata: " << b.size() << endl;

    return 0;
}