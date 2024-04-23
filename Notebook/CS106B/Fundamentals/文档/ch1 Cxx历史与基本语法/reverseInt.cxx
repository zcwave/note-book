#include <iostream>
using namespace std;

int reverseInt(int n) {
    int ri = 0;
    while (n > 0) {
        ri = ri * 10 + n % 10;
        n /= 10;
    }

    return ri;
}

int main() {

    int digit;

    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> digit;

    cout << "The reversed integer is " << reverseInt(digit) << endl;

}