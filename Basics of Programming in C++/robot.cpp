#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; 
    int position = 0;
    cin >> n;
    
    if (n < 1 || n > 100) {
        return 1;
    }
    
    string answersArr[n];

    for (int i = 0; i < n; i++) {
        string answer;
        
        cin >> ws;
        getline(cin, answer);
        
        if (answer == "LEWO") {
            answersArr[i] = answer;
            position--;
        }
        else if (answer == "PRAWO") {
            answersArr[i] = answer;
            position++;
        }
        else if (answer.substr(0, 5) == "JAK W") {
            int number = stoi(answer.substr(6)) - 1;
            answer = answersArr[number];
            if (answer == "LEWO") {
                position--;
            } else if (answer == "PRAWO") {
                position++;
            }
            answersArr[i] = answer;
        }
    }

    cout << position << endl;
    
    return 0;
}