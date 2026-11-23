// Vjezba 6, zadatak 3: napisite klasu LogFile i funkciju log_songs iznad main.

#define _CRT_SECURE_NO_WARNINGS    // za Visual Studio: dopusta std::fopen
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ovdje napisite klasu LogFile i funkciju log_songs

class LogFile {
private:
    FILE* file;

public:
    LogFile(const string& name) {
        file = fopen(name.c_str(), "a");
    }

    ~LogFile() {
        if (file != nullptr) {
            fclose(file);
        }
    }

    LogFile(const LogFile&) = delete;
    LogFile& operator=(const LogFile&) = delete;

    void write(const string& line) {
        if (file != nullptr) {
            fputs(line.c_str(), file);
            fputs("\n", file);
        }
    }
};

int log_songs(const vector<string>& titles) {
    LogFile log("played.log");

    int count = 0;

    for (const string& title : titles) {
        if (title == "STOP") {
            return count;
        }

        log.write(title);
        count++;
    }

    return count;
}

int main()
{
    std::remove("played.log");     // brise datoteku iz prethodnog pokretanja
    int n = log_songs({"Superhero", "Sports", "STOP", "Matador"});
    std::cout << n << '\n';
    std::cout << log_songs({"One Rizla"}) << '\n';

    // ispis sadrzaja datoteke
    std::FILE* f = std::fopen("played.log", "r");
    char line[100];
    while (std::fgets(line, sizeof line, f))
        std::cout << line;
    std::fclose(f);
    return 0;
}

/*
Ocekivani ispis:

    2
    1
    Superhero
    Sports
    One Rizla
*/
