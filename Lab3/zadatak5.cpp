#include <iostream>
#include <string>
using namespace std;

string with_separators(string digits){
    int kraj=digits.length();

    for (int i=kraj -3; i>0; i-=3){
        if (digits[0]== '-'){
            if (i==1)
                break;
        }

        digits.insert(i, ".");
    }

    return digits;
}

string without_separators(string text){
    size_t pozicija;

    while ((pozicija=text.find('.')) != string::npos){
        text.erase(pozicija, 1);
    }

    return text;
}

int main(){
    string broj;

    cout << "unesite broj: ";
    cin >> broj;

    cout << "s tockama: " << with_separators(broj) << endl;
    cout << "bez tocki: " << without_separators(with_separators(broj)) << endl;

    return 0;
}