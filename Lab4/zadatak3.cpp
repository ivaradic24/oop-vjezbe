#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool starts_with(const string& s, const string& prefix){
    if (prefix.size() > s.size())
        return false;

    return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix){
    if (suffix.size() > s.size())
        return false;

    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main(){
    vector<string> files{
        "vjezba04.cpp", "slajdovi.pdf", "main.cpp",
        "README.md", "vjezba04.h", "notes.txt",
        "vjezba03.cpp"
    };

    int count=count_if(files.begin(), files.end(),
        [](const string& s){
            return ends_with(s, ".cpp");
        });
    
    cout << ".cpp datoteka: " << count << endl;

    files.erase(
        remove_if(files.begin(), files.end(),
            [](const string& s){
                return starts_with(s, "vjezba");
            }),
        files.end()
    );

    for (const string& file : files){
        cout << file << " ";
    }

    return 0;
}