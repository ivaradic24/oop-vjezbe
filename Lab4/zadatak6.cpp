#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

vector<string> split_words(const string& text) {
    vector<string> words;
    string word;
    stringstream ss(text);

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    vector<string> dictionary{
        "programski", "jezik", "c++", "je",
        "brz", "i", "mocan", "ali", "nije",
        "jednostavan", "za", "pocetnike"
    };

    sort(dictionary.begin(), dictionary.end());

    string sentence;
    cout << "recenica: ";
    getline(cin, sentence);

    vector<string> words = split_words(sentence);

    vector<string> unknown;

    for (string word : words) {

        word.erase(
            remove_if(word.begin(), word.end(),
                [](unsigned char c) {
                    return c == ',' || c == '.';
                }),
            word.end()
        );

        transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) {
                return tolower(c);
            });

        if (!binary_search(dictionary.begin(),
                           dictionary.end(), word)) {
            unknown.push_back(word);
        }
    }

    cout << "nepoznatih rijeci: "
         << unknown.size() << endl;

    for (const string& word : unknown) {
        cout << word << " ";
    }

    return 0;
}
