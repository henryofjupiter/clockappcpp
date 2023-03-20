#include <iostream>
#include <string>
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

//print menu to console
void printMenu(char* string [], unsigned int numStrings, unsigned char width) {
    //error detected in sense. unexpected type string
    cout << nCharString(25, '*') << endl;

    for (int i = 0; i < numStrings; ++i) {
        cout << '*' << ' ' << i + 1 << ' ' << '-' << ' ' << string[i];
        if (strlen(string[i]) == 14) {      //strlen() is a cstring function used to get length of index string[i]
            cout << nCharString(4, ' ');
        }
        else {
            cout << nCharString(6, ' ');
        }
        cout << '*' << endl;
    }
    cout << nCharString(25, '*') << endl;
}

//gets menu choice to max choice input from user and check if in range
unsigned int getMenuChoice(unsigned int maxChoice) {

    for (int i = 0; i <= 9; ++i) {
       if (maxChoice >= 1 && maxChoice <= 4) {
           break;
       }
       else {
           cin >> maxChoice;
       }
   }
   return maxChoice;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK"<< nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK"<< nCharString(6, ' ') << nCharString(1, '*') << endl;
    cout << endl;
    cout << nCharString(1,'*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
    cout << nCharString(1,'*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*')<< endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

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

    getMenuChoice(userInput);
    cin >> h >> m >> s;
    displayClocks(h, m, s);
}