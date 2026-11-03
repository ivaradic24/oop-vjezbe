#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v){
    int broj;

    do {
        cout << "unesite broj (0 za kraj): ";
        cin >> broj;

        if (broj!=0){
            v.push_back(broj);
        }

    } while (broj!=0);
}

void print_vector(const vector<int>& v){
    for (int broj : v){
        cout << broj << " ";
    }
    cout << endl;
}

int main(){

    vector<int> v;

    cout << "obican vektor: " << endl;

    for (int i=1; i<=20; i++){
        v.push_back(i);

        cout << "size: " << v.size()
             << " kapacitet: " << v.capacity() << endl;
    }

    vector<int> v2;
    v2.reserve(100);

    cout << "\nVektor s reserve(100):" << endl;

    for (int i=1; i<=20; i++){
        v2.push_back(i);

        cout << "size: " << v2.size()
             << " kapacitet: " << v2.capacity() << endl;
    }

    v2.shrink_to_fit();

    cout << "\nKapacitet nakon shrink_to_fit: "
         << v2.capacity() << endl;

    return 0;

}