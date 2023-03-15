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

int main() {
    const int n = 5;
    const char c = '*';

    cout << nCharString(n, c) << endl;
}