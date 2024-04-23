#include <cassert>
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

string replaceAll(const string &str, char c1, char c2) {
    string result = str;
    size_t found = 0;

    while (true) {
        found = result.find(c1, found);
        if (found == string::npos) break;
        result.at(found) = c2;
    }
    return result;
}
string replaceAll(const string &str, const string &s1, const string &s2) {
    string result = str;
    size_t found = 0;

    while (true) {
        found = result.find(s1, found);
        if (found == string::npos) break;
        result.replace(found, s1.length(), s2);
    }
    return result;
}

int main(){ 
    assert(replaceAll("nannies", "na",  "d") == "dnnies");
    cout << "test success!" << endl;
    return 0;
}

