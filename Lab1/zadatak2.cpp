#include <iostream>
#include <string>
#include <limits>
#include <ctime>

int main(){
    int godinaRodenja{};

    std::cout << "Unesi godinu rođenja: ";
    std::cin >> godinaRodenja;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string imeprezime{};

    std::cout << "unesi ime i prezime: ";
    std::getline(std::cin, imeprezime);

    std::cout << "inicijali: ";

    bool pocetakrijeci{true};

    for (char znak : imeprezime){
        if (znak != ' ' && pocetakrijeci){
            std::cout << znak << '.';
        }

        pocetakrijeci=(znak==' ');
    }

    std::cout << '\n';

    int brojznakova{0};

    for (char znak:imeprezime){
        if (znak != ' '){
            brojznakova++;
        }
    }

    std::cout << "Broj znakova bez razmaka: " << brojznakova << '\n';

    std::time_t trenutnovrijeme{std::time(nullptr)};
    std::tm* datum{std::localtime(&trenutnovrijeme)};
    int tekucagodina{datum->tm_year+1900};

    std::cout << "godina koju osoba navršava: " << tekucagodina - godinaRodenja << '\n';

    return 0;

}
