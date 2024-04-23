#include <iostream>
#include <sstream>
#include "simpio.h"

using std::cout;    using std::endl;
using std::cin;     using std::string;


string SimpleIO::IntegerToString(int myInt) {
    std::ostringstream converter;
    converter << myInt;
    return converter.str();
}

int SimpleIO::StringToInteger(const string& str) {
    std::istringstream converter(str);
    int value;
    if(converter >> value) {
        char rem;
        if(converter >> rem) {
            throw std::domain_error(string("Unexpected character in input: ") + rem);
        }
        return value;
    }
    throw std::domain_error(string("Failed to convert input: ") + str);
}

int SimpleIO::getInteger() {
    while(true) {
        string line;
        std::getline(cin, line);
        std::istringstream converter(line);
        int result;
        if(converter >> result) {
            char remaining;
            if(converter >> remaining) {
                cout << "Unexpected character. Try again." << endl;
            } else {
                return result;
            }
        } else {
            cout << "Not a valid integer. Try again." << endl;
        }
    }
}
