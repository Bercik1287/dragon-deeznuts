#include <iostream>

using namespace std;

struct Wezel {
    int dane;
    Wezel* poprzedni;
    Wezel* nastepny;
    
    Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
};

class ListaDwukierunkowa {
private:
    Wezel* przod;
    Wezel* tyl;
    
public:
    ListaDwukierunkowa() : przod(nullptr), tyl(nullptr) {}
    
    void dodajZPrzodu(int wartosc) {
        Wezel* Wezel2 = new Wezel(wartosc);
        if (!przod) {
            przod = tyl = Wezel2;
        } else {
            Wezel2->nastepny = przod;
            przod->poprzedni = Wezel2;
            przod = Wezel2;
        }
    }

void dodajZTylu(int wartosc) {
        Wezel* Wezel2 = new Wezel(wartosc);
        if (!tyl) {
            przod = tyl = Wezel2;
        } else {
            Wezel2->poprzedni = tyl;
            tyl->nastepny = Wezel2;
            tyl = Wezel2;
        }
    }

void dodajDoIndeksu(int indeks, int wartosc) {
        if (indeks == 0) {
            dodajZPrzodu(wartosc);
            return;
        }
        Wezel* obecny = przod;
        int obecnyIndeks = 0;
        while (obecny && obecnyIndeks < indeks) {
            obecny = obecny->nastepny;
            obecnyIndeks++;
        }
        if (!obecny) {
            dodajZTylu(wartosc);
        } else {
            Wezel* Wezel2 = new Wezel(wartosc);
            Wezel2->poprzedni = obecny->poprzedni;
            Wezel2->nastepny = obecny;
            if (obecny->poprzedni) {
                obecny->poprzedni->nastepny = Wezel2;
            }
            obecny->poprzedni = Wezel2;
        }
    }
}

int main() {
    
    return 0;
}