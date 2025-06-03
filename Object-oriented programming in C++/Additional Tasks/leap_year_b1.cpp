#include <iostream>

using namespace std;

bool czyPrzestepny(int rok) {
    if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;
    if(N >= 1000) return 1;
    for(int i = 0; i < N; i++) {
        int rok;
        cin >> rok;
        if(rok > 32000) return 1;
        if(czyPrzestepny(rok)) {
            cout << rok << " - " << "rok przestepny" << endl;
        } else {
            cout << rok << " - " << "rok normalny" << endl;
        }
    }
    return 0;
}