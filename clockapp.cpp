#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <cstring>

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

void printMenu(char* string [], unsigned int numStrings, unsigned char width) {

    cout << nCharString(25, '*') << endl;

    for (int i = 0; i < numStrings; ++i) {
        cout << '*' << ' ' << i + 1 << ' ' << '-' << ' ' << string[i];
        if (strlen(string[i]) == 14) {
            cout << nCharString(4, ' ');
        }
        else {
            cout << nCharString(6, ' ');
        }
        cout << '*' << endl;
    }
    cout << nCharString(25, '*') << endl;
}

int main() {
    char stringWidth = ' ';
    const unsigned int NUM_STRINGS = 4;
    char* menuString[NUM_STRINGS] = {"Add One Hour", "Add One Minute", "Add One Second", "Exit Program"};
    const int n = 5;   //for testing
    const char c = '*'; //for testing
    int h, m, s;        //for testing

    int userInput;

    printMenu(menuString, NUM_STRINGS, stringWidth);

    cin >> userInput;
    cout << nCharString(n, c) << endl;
    cout << twoDigitString(userInput) << endl;
    cin >> h >> m >> s;
    cout << formatTime24(h, m, s) << endl;
    cout << formatTime12(h, m, s) << endl;

}