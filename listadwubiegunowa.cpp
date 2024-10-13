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
    
}

int main() {
    
    return 0;
}