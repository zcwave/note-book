#ifndef __SIMPIO__
#define __SIMPIO__
#include <string>

class SimpleIO {
public:
    std::string IntegerToString(int myInt);
    int StringToInteger(const std::string& str);
    int getInteger();
};

#endif