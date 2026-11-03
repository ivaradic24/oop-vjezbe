#include <iostream>
#include <string>
using namespace std;

bool split_email(const string& email, string& user, string& domain){
    size_t at=email.find('@');

    if (at==string::npos || at !=email.rfind('@'))
        return false;

    if (at==0 || at == email.length() -1)
        return false;

    user=email.substr(0, at);
    domain=email.substr(at+1);

    if (domain.find('.')==string::npos)
        return false;

    return true;

}

int main(){

    string email, user, domain;

    cout << "unesite email: ";
    getline(cin, email);

    if (split_email(email, user, domain)){
        cout << "korisnik: " << user << endl;
        cout << "domena: " << domain << endl;
    } else{
        cout << "neispravna adresa" << endl;
    }

    return 0;

}