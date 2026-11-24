// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// ovdje napisite klasu Money i operatore

class Money {
    int cents;

public:
    Money(int euros = 0, int cents = 0)
        : cents(euros * 100 + cents) {}

    Money& operator+=(const Money& other) {
        cents += other.cents;
        return *this;
    }
    
    friend Money operator+(Money a, const Money& b) {
        a += b;
        return a;
    }

    friend bool operator<(const Money& a, const Money& b) {
        return a.cents < b.cents;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        out << m.cents / 100 << '.';

        int remainder = m.cents % 100;

        if (remainder < 10)
            out << '0';

        out << remainder << " EUR";
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        int euros;
        char separator;
        int cents;

        if (in >> euros >> separator >> cents) {
            if (separator != '.') {
                in.setstate(ios::failbit);
            } else {
                m.cents = euros * 100 + cents;
            }
        }

        return in;
    }
};

int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/
