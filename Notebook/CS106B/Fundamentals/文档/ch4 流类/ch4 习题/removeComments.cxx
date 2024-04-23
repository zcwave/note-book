#include <iostream>
#include <string>
#include <vcruntime.h>
using namespace std;

using State = enum { START, CONTINUE, FINISH };

void removeComments(istream &is, ostream &os) {
    // 仅处理输入是ifstream的情景。
    string line;
    State s = START;
    
    while (getline(is, line)) {

        size_t pos = line.find("//");

        

        if (s == START)
            os << line;
        else if (s == FINISH) {
            string lf = line.substr(line.length() - 3);
            if (lf == "*/") {
                s = START;
            }
        }
    }
}