#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_words(const string& tekst) {
    vector<string> rijeci;
    size_t pocetak = 0;

    while (pocetak < tekst.length()) {
        while (pocetak < tekst.length() && tekst[pocetak] == ' ') {
            pocetak++;
        }

        if (pocetak >= tekst.length()) break;

        size_t kraj = tekst.find(' ', pocetak);

        if (kraj == string::npos) {
            kraj = tekst.length();
        }

        rijeci.push_back(tekst.substr(pocetak, kraj - pocetak));
        pocetak = kraj + 1;
    }

    return rijeci;
}

int main() {
    string tekst;
    cout << "Unesite recenicu: ";
    getline(cin, tekst);

    vector<string> rijeci = split_words(tekst);

    cout << "Broj rijeci: " << rijeci.size() << endl;

    if (!rijeci.empty()) {
        string najdulja = rijeci[0];
        string prva = rijeci[0];

        for (string rijec : rijeci) {
            if (rijec.length() > najdulja.length()) {
                najdulja = rijec;
            }

            if (rijec < prva) {
                prva = rijec;
            }
        }

        string obrnuto = "";

        for (int i = (int)rijeci.size() - 1; i >= 0; i--) {
            obrnuto += rijeci[i];

            if (i > 0) {
                obrnuto += "-";
            }
        }

        cout << "Najdulja rijec: " << najdulja << endl;
        cout << "Obrnuti redoslijed: " << obrnuto << endl;
        cout << "Prva po abecedi: " << prva << endl;
    }

    return 0;
}