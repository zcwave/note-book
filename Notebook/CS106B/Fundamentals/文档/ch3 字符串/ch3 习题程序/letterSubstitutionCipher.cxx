#include <cassert>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

string letterSubstitionCipher(  const string& message, 
                                const string &cipher_table) {
    string result;
    for (auto ch : message) {
        if (isalpha(ch)) {
            int offset = ch - 'A';
            assert(offset > 0);
            result += cipher_table[offset];
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {

    cout << "Letter substitution cipher." << endl;
    string ct, msg;
    cout << "Enter a 26-letter key: ";
    getline(cin, ct);
    assert(ct.length() == 26);
    
    cout << "Enter a message: ";
    getline(cin, msg);
    cout << "Encoded message: " << letterSubstitionCipher(msg, ct);
    return 0;
}