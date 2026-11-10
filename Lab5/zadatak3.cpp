#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song{

public:
    string title;
    string artist;
    int seconds;
};

class Album{

private:
    string title;
    int year;
    vector<Song> songs;

public:
    Album(string t, int y, Song first)
        : title(t), year(y)
    {
        songs.push_back(first);
    }

    bool add(Song s){
        for (const Song& song:songs){
            if (song.title==s.title){
                return false;
            }
        }

        songs.push_back(s);
        return true;
    }

    int duration() const{
        int total=0;

        for (const Song& song:songs){
            total += song.seconds;
        }

        return total;
    }

    void print() const{
        cout << title << " (" << year << ")" << endl;

        for (const Song& song : songs){
            cout << song.title << " - "
                 << song.artist << " - "
                 << song.seconds << " s" << endl;
        }

        cout << "ukupno trajanje: "
             << duration() << " s" << endl;
    }
};

int main(){

    Song s1={"pjesma 1", "pjevac", 180};
    Song s2={"pjesma 2", "pjevac 2", 210};
    Song s3={"pjesma 3", "pjevac 3", 190};

    Album a("album 1", 2026, s1);

    a.add(s2);
    a.add(s3);

    a.print();

    return 0;

}