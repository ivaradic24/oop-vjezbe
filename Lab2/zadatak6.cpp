
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void ispisi(Student& s) {
    cout << s.ime << " " << s.jmbag
         << ", godina: " << s.godina
         << ", ECTS: " << s.ects
         << ", prosjek: " << s.prosjek << endl;
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

void filter_students(
    Student s[],
    int n,
    void (*action)(Student&),
    bool (*cond)(const Student&)
) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {
    Student studenti[] = {
        {"Ana", "123", 1, 30, 4.2},
        {"Marko", "456", 1, 0, 3.1},
        {"Iva", "789", 2, 50, 4.5},
        {"Luka", "321", 3, 45, 3.8}
    };

    int n = 4;

    cout << "Studenti prve godine koji imaju barem jedan ispit:" << endl;
    filter_students(studenti, n, ispisi, [](const Student& s) {
        return s.godina == 1 && s.ects > 0;
    });

    cout << "\nStudenti s prosjekom vecim od 3.5:" << endl;
    filter_students(studenti, n, ispisi, [](const Student& s) {
        return s.prosjek > 3.5;
    });

    cout << "\nPovecanje godine studentima s barem 45 ECTS:" << endl;
    filter_students(studenti, n, povecaj_godinu, [](const Student& s) {
        return s.ects >= 45;
    });

    cout << "\nStudenti nakon promjene godine:" << endl;
    for (int i = 0; i < n; i++) {
        ispisi(studenti[i]);
    }

    return 0;
}
