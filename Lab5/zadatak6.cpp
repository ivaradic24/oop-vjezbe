// Vjezba 5, zadatak 6: napisite klasu Coin iznad funkcije bonus.

#include <iostream>
using namespace std;

// ovdje napisite klasu Coin

class Coin{

private:
    int value;
    static int counter;

public:
    Coin(int v) : value(v){
        counter++;
    }

    //destruktor
    ~Coin(){
        counter--;
    }

    static int remaining(){
        return counter;
    }
};

int Coin::counter=0;

void bonus()               // bonus runda: tri novcica
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    cout << Coin::remaining() << '\n';
}

int main()
{
    cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        cout << Coin::remaining() << '\n';
    }
    cout << Coin::remaining() << '\n';
    bonus();
    cout << Coin::remaining() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    3
    1
    4
    1
*/
