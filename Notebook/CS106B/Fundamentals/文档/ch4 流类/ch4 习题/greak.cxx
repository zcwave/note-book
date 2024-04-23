#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

static void initRandomSeed() {
   static bool initialized = false;
   if (!initialized) {
      srand(int(time(NULL)));
      initialized = true;
   }
}
int randomInteger(int low, int high) {
   initRandomSeed();
   double d = rand() / (double(RAND_MAX) + 1);
   double s = d * (double(high) - low + 1);
   return int(floor(low + s));
}




string greek(const string& text) {
    string r_text;
    for (auto ch : text) {
        if (isalpha(ch)) {
            int offset = randomInteger(0, 25);
            assert(offset >= 0 && offset < 26);
            if (isupper(ch)) {
                r_text += 'A' + offset;
            } else {
                assert(islower(ch));
                r_text += 'a' + offset;
            }
        } else {
            r_text += ch;
        }
    }
    return r_text;
}
int main() {
    string file_name;
    cout << "Input file: ";
    cin >> file_name;

    string line;
    ifstream in_file(file_name);
    getline(in_file, line); //偷懒了，由于源文件只有一行。

    cout << greek(line);

    return 0;
}