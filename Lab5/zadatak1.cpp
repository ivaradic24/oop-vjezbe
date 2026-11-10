#include <iostream>
#include <cassert>
using namespace std;

class Volume{

private:
    int level;
    int previousLevel;

    static int limit(int l){
        if (l<0)
            return 0;
        if (l>100)
            return 100;
        return l;
    }

    bool valid() const {
        return level >= 0 && level<=100;
    }

public:
    Volume(int l){
        level=limit(l);
        previousLevel=level;
        assert(valid());
    }

    Volume() : Volume(50) {}

    void up(int step=10) {
        level=limit(level+step);
        assert(valid());
    }

    void down(int step=10){
        level=limit(level-step);
        assert(valid());
    }

    void mute(){
        if (level!=0){
            previousLevel=level;
            level=0;
        }
        assert(valid());
    }

    void unmute(){
        level=previousLevel;
        assert(valid());
    }

    void print() const{
        cout << "Volume: " << level << endl;
    }

};

int main(){
    Volume v(70);

    v.print();

    v.up();
    v.print();

    v.down(20);
    v.print();

    v.mute();
    v.print();

    v.unmute();
    v.print();

    return 0;
}