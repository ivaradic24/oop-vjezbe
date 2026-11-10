#include <iostream>
#include <string>
using namespace std;

class Clip{
    int length;
    int start;
    int end;
    string name;
    const int max_length;

public:
    Clip(const string& name, int s, int e)
        : length(e-s),
        start(s),
        end(e),
        name(name),
        max_length(600){}

    void print() const {
        cout << name << ": " << length << " s\n";
    }
};

int main(){
    Clip c("Concrete (Shame)", 10, 190);
    c.print();

    return 0;
}