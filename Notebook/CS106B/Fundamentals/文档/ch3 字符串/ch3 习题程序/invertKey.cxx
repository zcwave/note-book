#include <cassert>
#include <cctype>
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

string invertKey(const string& secret_msg, const string &key) {
    string plaintext_msg;
    for (auto ch : secret_msg) {
        if (isalpha(ch)) {
            size_t offset = key.find(ch);
            assert(offset != string::npos);
            plaintext_msg += 'A' + offset;
        } else {
            plaintext_msg += ch;
        }
    }
    return plaintext_msg;
}

int main() {

    cout << "Letter substitution cipher." << endl;
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string msg = "VGKATKL GY ZIT VGKSR XFOZT!";
    // cout << "Enter a 26-letter key: ";
    // getline(cin, ct);
    // assert(ct.length() == 26);
    
    // cout << "Enter a message: ";
    // getline(cin, msg);
    cout << "Encoded message: " << invertKey(msg, key);
    return 0;
}