#include <iostream>
using namespace std;

class Kostka {
    public:
        int Top;
        int N;
        int W;
        int E;
        int S;
        int Bottom;
        
        Kostka() {
            Top = 1;
            N = 2;
            W = 3;
            E = 4;
            S = 5;
            Bottom = 6;
        }   
        void pokaz_Kostke() {
            cout << Top << endl;
        }
        
        int obroc_Kostke(char kierunek) {
            if(kierunek == 'N') {
                int Waiting = S;
                S = Bottom;
                Bottom = N;
                N = Top;
                Top = Waiting;
            }
            else if(kierunek == 'S') {
                int Waiting = S;
                S = Top;
                Top = N;
                N = Bottom;
                Bottom = Waiting;
            }
            else if(kierunek == 'W') {
                int Waiting = E;
                E = Bottom;
                Bottom = W;
                W = Top;
                Top = Waiting;
            }
            else if(kierunek == 'E') {
                int Waiting = E;
                E = Top;
                Top = W;
                W = Bottom;
                Bottom = Waiting;
            } else return false;
            return true;
        }
        
};


int main() {
    Kostka p;
    string s;
    getline(cin, s);
    for(char c : s) {
        p.obroc_Kostke(c);
    }
    p.pokaz_Kostke();
    
    return 0;
}