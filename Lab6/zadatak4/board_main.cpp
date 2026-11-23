// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>
using namespace std;

// ovdje napisite klasu Board

class Board {
private:
    int r;
    int c;
    char border;
    char* data;

public:
    Board(int rows, int cols, char ch) {
        r = rows;
        c = cols;
        border = ch;

        data = new char[r * c];

        for (int i = 0; i < r * c; i++) {
            data[i] = border;
        }
    }

    ~Board() {
        delete[] data;
    }

    Board(const Board& other) {
        r = other.r;
        c = other.c;
        border = other.border;

        data = new char[r * c];

        for (int i = 0; i < r * c; i++) {
            data[i] = other.data[i];
        }
    }

    void set(int i, int j, char ch) {
        if (i > 0 && i < r - 1 &&
            j > 0 && j < c - 1) {
            data[i * c + j] = ch;
        }
    }

    char get(int i, int j) const {
        return data[i * c + j];
    }

    int rows() const {
        return r;
    }

    int cols() const {
        return c;
    }

    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << data[i * c + j];
            }
            cout << '\n';
        }
    }
};

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;          // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');     // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
