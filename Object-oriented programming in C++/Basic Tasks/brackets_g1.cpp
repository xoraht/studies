#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool sprawdz(const string& linia) {
    stack<char> stos;
    for(char znak : linia) {
        if(znak == '(' || znak == '[') stos.push(znak);
        else if(znak == ')') {
            if(stos.empty() || stos.top() != '(') return false;
            stos.pop();
        }
        else if(znak == ']') {
            if(stos.empty() || stos.top() != '[') return false;
            stos.pop();
        }
    }
    return stos.empty();
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        string linia;
        getline(cin, linia);
        cout << (sprawdz(linia) ? "TAK" : "NIE") << endl;     
    }
    return 0;
}