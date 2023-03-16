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

//remember to make commit before proceeding
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string newString;

    newString = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    return newString;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    // FIX ME: excessive conditions

    string newString;
    if (h == 0) {
        newString = twoDigitString(h + 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }
    if (h >= 1 && h < 12) {
        newString = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";

    }
    if (h >= 12 && h <= 24) {
        if (h > 12) {
            newString = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
        }
        else {
            newString = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
        }
    }
    return newString;
}



int main() {
    const int n = 5;   //for testing
    const char c = '*'; //for testing
    int h, m, s;        //for testing

    int userInput;

    cin >> userInput;
    cout << nCharString(n, c) << endl;
    cout << twoDigitString(userInput) << endl;
    cin >> h >> m >> s;
    cout << formatTime24(h, m, s) << endl;
    cout << formatTime12(h, m, s) << endl;

}