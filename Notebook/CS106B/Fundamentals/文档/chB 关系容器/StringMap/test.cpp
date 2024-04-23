#include "StringMap.hpp"

#include <cassert>
#include <iostream>
using namespace std;

int main() {
    StringMap sm;
    string key = "hello";
    sm.put(key, "world");
    sm.put(key, "world");

    cout << sm.get(key);
    return 0;
}