#include <iostream>
#include "random.h"
using namespace std;

void consecutiveHeads() {
    int count = 0;
    int tc = 0;
    double p = .5;
    while (tc < 3) {
        if (randomChance(p)) {
            cout << "heads" << endl;
            tc++;
        }
        else {
            cout << "tails" << endl;
        }
        count++;
    }
    cout << "It took " << count << " filps to get " 
        << tc << " consecutive heads." << endl;
}

int main() {
    consecutiveHeads();
    return 0;
}