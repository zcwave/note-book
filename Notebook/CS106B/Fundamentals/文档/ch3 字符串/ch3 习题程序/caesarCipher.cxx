#include <cctype>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

string caesarCipher(const string &rhs, int shift) {
    string result = rhs;
    for (auto &ch : result) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = 'A' + (ch - 'A' + shift + 26) % 26;
            } else {
                assert(islower(ch));
                ch = 'a' + (ch - 'a' + shift + 26) % 26;
            }
        }
    }
    return result;
}

int main() {
    cout << "This program encodes a message using a Caesar cipher." << endl
         << "Enter the number of character positions ot shift: ";
    int shift;
    cin >> shift;
    cin.ignore();
    string line;
    cout << "Enter a message: ";
    getline(cin, line);
    cout << "Encoded message: " << caesarCipher(line, shift);
    return 0;
}