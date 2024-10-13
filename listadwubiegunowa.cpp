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

    void usunZPrzodu() {
        if (!przod) return;
        
        Wezel* temp = przod;
        if (przod == tyl) {
            przod = tyl = nullptr;
        } else {
            przod = przod->nastepny;
            przod->poprzedni = nullptr;
        }
        delete temp;
    }
    void usunZTylu() {
        if (!tyl) return;
        
        Wezel* temp = tyl;
        if (przod == tyl) {
            przod = tyl = nullptr;
        } else {
            tyl = tyl->poprzedni;
            tyl->nastepny = nullptr;
        }
        delete temp;
    }
    void usunZIndeksu(int indeks) {
        if (indeks == 0) {
            usunZPrzodu();
            return;
        }
        
        Wezel* obecny = przod;
        int obecnyIndeks = 0;
        
        while (obecny && obecnyIndeks < indeks) {
            obecny = obecny->nastepny;
            obecnyIndeks++;
        }
        
        if (!obecny) return;
        
        if (obecny->poprzedni) obecny->poprzedni->nastepny = obecny->nastepny;
        if (obecny->nastepny) obecny->nastepny->poprzedni = obecny->poprzedni;
        
        if (obecny == przod) przod = obecny->nastepny;
        if (obecny == tyl) tyl = obecny->poprzedni;
        
        delete obecny;
    }

    void wyswietl() {
        Wezel* obecny = przod;
        while (obecny) {
            cout << obecny->dane << " ";
            obecny = obecny->nastepny;
        }
        cout << endl;
    }

    void wyswietlOdwrotnie() {
        Wezel* obecny = tyl;
        while (obecny) {
            cout << obecny->dane << " ";
            obecny = obecny->poprzedni;
        }
        cout << endl;
    }

    void wyswietlNastepny(Wezel* Wezel) {
        if (Wezel && Wezel->nastepny) {
            cout << "Następny element: " << Wezel->nastepny->dane << endl;
        } else {
            cout << "Brak następnego elementu." << endl;
        }
    }

    void wyswietlPoprzedni(Wezel* Wezel) {
        if (Wezel && Wezel->poprzedni) {
            cout << "Poprzedni element: " << Wezel->poprzedni->dane << endl;
        } else {
            cout << "Brak poprzedniego elementu." << endl;
        }
    }

    void clear() {
        while (przod) {
            usunZPrzodu();
        }
    }
    Wezel* znajdzprzod() {
        return przod;
    }
    Wezel* znajdztyl() {
        return tyl;
    }
};

int main() {
    
    ListaDwukierunkowa lista;

        lista.dodajZPrzodu(10);
        lista.dodajZPrzodu(20);
        lista.dodajZTylu(30);
        lista.dodajDoIndeksu(1, 25);
  
        cout << "Lista: ";
        lista.wyswietl();
    
        cout << "Lista w odwrotnej kolejnosci: ";
        lista.wyswietlOdwrotnie();
    
        lista.usunZPrzodu();
        lista.usunZTylu();
    
        cout << "Lista po usunieciu: ";
        lista.wyswietl();
    
        lista.usunZIndeksu(1);
    
        cout << "Lista po usunieciu elementu z indeksem 1: ";
        lista.wyswietl();
    
        Wezel* przod = list.znajdzprzod();
        lista.wyswietlNastepny(przod);
        lista.wyswietlPoprzedni(przod);
    
        list.clear();
        cout << "Lista po wyczyszczeniu: ";
        lista.wyswietl();

    return 0;
}