#include <iostream>
using namespace std;

int findLargest(const int SENTINEL) {
    cout << "This program finds the largest integer in a list. \n"
         << "Enter 0 to signal the end of the list." 
         << endl;
    int total_num;
    int max = 0;
    while (true) {
        cout << "? ";
        cin >> total_num;
        if (total_num == SENTINEL) break;
        if (total_num > max) {
            max = total_num;
            // cout << max << endl;
        }
    }
    return max;
}


int main() {
    const int SENTINEL = 0;
    int largest = findLargest(SENTINEL);
    cout << "The largest number is: " << largest << endl;
    
    return 0;


}