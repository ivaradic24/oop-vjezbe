#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string clean(const string& word) {
    string result;

    for (char c : word) {
        if (isalpha(static_cast<unsigned char>(c))) {
            result += static_cast<char>(
                tolower(static_cast<unsigned char>(c))
            );
        }
    }

    return result;
}

struct WordCount {
    string word;
    int count;
};

int main() {
    ifstream in("tekst.txt");

    if (!in) {
        cout << "Datoteka ne postoji\n";
        return 1;
    }

    map<string, int> freq;
    string word;

    while (in >> word) {
        word = clean(word);

        if (!word.empty()) {
            ++freq[word];
        }
    }

    cout << "razlicitih rijeci: " << freq.size() << '\n';

    cout << "alice: " << freq["alice"] << '\n';

    vector<WordCount> words;

    for (const auto& pair : freq) {
        words.push_back({pair.first, pair.second});
    }

    sort(words.begin(), words.end(),
        [](const WordCount& a, const WordCount& b) {
            if (a.count != b.count)
                return a.count > b.count;

            return a.word < b.word;
        }
    );

    for (int i = 0; i < 5 && i < static_cast<int>(words.size()); ++i) {
        cout << words[i].word << ": "
                << words[i].count << '\n';
    }

    return 0;
}
