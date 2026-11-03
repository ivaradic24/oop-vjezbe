#include <iostream>
#include <vector>
using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours){
    double suma=0;

    for (double h : hours){
        suma +=h;
    }

    return suma;
}

int best_day(const array<double, DAYS>& hours){
    int najbolji=0;

    for (int i=1; i<DAYS; i++){
        if (hours[i]>hours[najbolji]){
            najbolji=i;
        }
    }

    return najbolji+1;
}

int main(){

    array<double, DAYS> prvi;

    cout << "unesite sate ucenja za 7 dana: " << endl;

    for (int i=0; i<DAYS; i++){
        cin >> prvi[i];
    }

    cout << "ukupno sati: " << total(prvi) << endl;
    cout << "najvise ucila: dan " << best_day(prvi) << endl;

    array<double, DAYS> drugi;
    drugi.fill(1.5);

    cout << "drugi tjedan ukupno: " << total(drugi) << endl;

    cout << "jednaki tjedni: " << (prvi == drugi) << endl;
    cout << "prvi manji od drugog: " << (prvi<drugi) << endl;

    prvi.swap(drugi);

    cout << "nakon zamjene: " << endl;
    cout << "prvi tjedan: " << total(prvi) << endl;
    cout << "drugi tjedan: " << total(drugi) << endl;

    return 0;
}