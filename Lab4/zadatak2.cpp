#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    int year;
    int plays;
};

void print_song(const Song& s) {
    cout << s.title << " - " << s.artist
         << " (" << s.year << "), slusanja: "
         << s.plays << endl;
}

int main() {
    vector<Song> songs{
        {"Kafana na Balkanu", "Aca Lukas", 1995, 1500},
        {"Luda za tobom", "Lepa Brena", 1993, 2500},
        {"Crno i zlatno", "Seka Aleksic", 2002, 2700},
        {"Ako me ostaviš", "Mišo Kovač", 1980, 4800},
        {"Geni kameni", "Thompson", 1996, 5000}
    };

    sort(songs.begin(), songs.end(),
        [](const Song& a, const Song& b) {
            if (a.year != b.year)
                return a.year < b.year;

            return a.title < b.title;
        });

    cout << "sortirane pjesme:" << endl;
    for (const Song& s : songs) {
        print_song(s);
    }

    string ime;
    cout << "unesite izvodaca: ";
    getline(cin >> ws, ime);

    int broj = count_if(songs.begin(), songs.end(),
        [&ime](const Song& s) {
            return s.artist == ime;
        });

    cout << "broj pjesama: " << broj << endl;

    auto najstarija = find_if(songs.begin(), songs.end(),
        [&ime](const Song& s) {
            return s.artist == ime;
        });

    if (najstarija != songs.end()) {
        cout << "najstarija pjesma: ";
        print_song(*najstarija);
    }
    else {
        cout << "izvodac nije pronaden." << endl;
    }

    auto najslusanija = max_element(
        songs.begin(), songs.end(),
        [](const Song& a, const Song& b) {
            return a.plays < b.plays;
        });

    cout << "najslusanija pjesma: ";
    print_song(*najslusanija);

    return 0;
}
