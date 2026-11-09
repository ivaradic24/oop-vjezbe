#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const string& password) {
    PasswordInfo info;

    info.length = password.length();

    info.digits = count_if(password.begin(), password.end(),
        [](unsigned char c) {
            return isdigit(c);
        });

    info.uppercase = count_if(password.begin(), password.end(),
        [](unsigned char c) {
            return isupper(c);
        });

    info.special = count_if(password.begin(), password.end(),
        [](unsigned char c) {
            return ispunct(c);
        });

    return info;
}

bool is_strong(const PasswordInfo& info) {
    return info.length >= 10 &&
           info.digits >= 1 &&
           info.uppercase >= 1 &&
           info.special >= 1;
}

int main() {
    string password;

    cout << "unesite lozinku: ";
    cin >> password;

    PasswordInfo info = analyze(password);

    cout << "duljina: " << info.length << endl;
    cout << "znamenke: " << info.digits << endl;
    cout << "velika slova: " << info.uppercase << endl;
    cout << "posebni znakovi: " << info.special << endl;

    if (is_strong(info))
        cout << "lozinka je jaka." << endl;
    else
        cout << "lozinka je slaba." << endl;

    return 0;
}
