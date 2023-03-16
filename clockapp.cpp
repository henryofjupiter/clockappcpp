#include <iostream>
#include <string>

using namespace std;

string nCharString(size_t n, char c) {
    string newString;

    for (int i = 0; i < n; ++i) {
        newString += c;
    }
    return newString;
}

//make commit before proceeding
string twoDigitString(unsigned int n) {
    string newString;

    for (int i = 0; i < 60; ++i) {
        if (n >= 0 && n <= 9) {
            if (n == i) {
                newString = "0" + to_string(n);
            }
        }
        else {
            newString = to_string(n);
        }
    }
    return newString;
}

int main() {
    const int n = 5;
    const char c = '*';
//make commit before proceeding
    int userInput;

    cin >> userInput;
    cout << nCharString(n, c) << endl;
    cout << twoDigitString(userInput) << endl;
}