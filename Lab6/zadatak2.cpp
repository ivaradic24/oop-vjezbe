#include <iostream>
#include <string>

using namespace std;

// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

// ovdje napisite klasu Ticket

class Ticket{
private:
    string concert;
    int id;
    static int counter;

public:
    Ticket(const string& name)
        : concert(name), id(++counter) {}

    Ticket(const Ticket&) = delete;

    int get_id() const{
        return id;
    }

    static int issued(){
        return counter;
    }

};

int Ticket::counter=0;

void print(const Ticket& t){
    cout << t.get_id() << '\n';
}

int main()
{
    cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");

    print(t1);

    cout << t1.get_id() << ' '
         << t2.get_id() << ' '
         << t3.get_id() << '\n';
         
    cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/