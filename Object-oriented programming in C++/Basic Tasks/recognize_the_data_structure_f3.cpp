#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int,int>> operacje(n);
        for (int i = 0; i < n; i++) cin >> operacje[i].first >> operacje[i].second;
        bool mozliwy_stos = true, mozliwa_kolejka = true, mozliwa_prio = true;
        stack<int> stos;
        queue<int> kolejka;
        priority_queue<int> prio;
        int typy = 0;
        for (int i = 0; i < n; i++) {
            int op = operacje[i].first, x = operacje[i].second;
            if (op == 1) {
                if (mozliwy_stos) stos.push(x);
                if (mozliwa_kolejka) kolejka.push(x);
                if (mozliwa_prio) prio.push(x);
            } else {
                if (mozliwy_stos) {
                    if (stos.empty() || stos.top() != x) mozliwy_stos = false;
                    else stos.pop();
                }
                if (mozliwa_kolejka) {
                    if (kolejka.empty() || kolejka.front() != x) mozliwa_kolejka = false;
                    else kolejka.pop();
                }
                if (mozliwa_prio) {
                    if (prio.empty() || prio.top() != x) mozliwa_prio = false;
                    else prio.pop();
                }
            }
        }
        int ile_mozliwych = (int)mozliwy_stos + (int)mozliwa_kolejka + (int)mozliwa_prio;
        if (ile_mozliwych == 0) cout << "niemozliwe\n";
        else if (ile_mozliwych > 1) cout << "brak pewnosci\n";
        else if (mozliwy_stos) cout << "stos\n";
        else if (mozliwa_kolejka) cout << "kolejka\n";
        else if (mozliwa_prio) cout << "kolejka priorytetowa\n";
    }
    return 0;
}