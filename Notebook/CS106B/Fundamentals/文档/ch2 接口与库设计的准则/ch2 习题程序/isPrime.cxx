#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 2) { 
        return n == 2;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test cases
    assert(!isPrime(0)); // 0不是素数
    assert(!isPrime(1)); // 1不是素数
    assert(isPrime(2)); // 2是素数
    assert(isPrime(3)); // 3是素数
    assert(!isPrime(4)); // 4不是素数
    assert(isPrime(5)); // 5是素数
    assert(!isPrime(6)); // 6不是素数
    assert(isPrime(7)); // 7是素数
    assert(!isPrime(8)); // 8不是素数
    assert(!isPrime(9)); // 9不是素数
    assert(!isPrime(10)); // 10不是素数
    assert(isPrime(11)); // 11是素数
    assert(isPrime(13)); // 13是素数
    assert(!isPrime(15)); // 15不是素数
    assert(isPrime(17)); // 17是素数
    assert(isPrime(19)); // 19是素数
    assert(!isPrime(21)); // 21不是素数
    assert(isPrime(23)); // 23是素数
    assert(!isPrime(25)); // 25不是素数
    assert(!isPrime(27)); // 27不是素数
    assert(isPrime(29)); // 29是素数
    assert(isPrime(31)); // 31是素数
    assert(isPrime(37)); // 37是素数
    assert(!isPrime(39)); // 39不是素数
    assert(!isPrime(49)); // 49不是素数
    assert(!isPrime(121)); // 121不是素数
    assert(!isPrime(169)); // 169不是素数
    assert(isPrime(127)); // 127是素数
    assert(isPrime(131)); // 131是素数
    assert(isPrime(137)); // 137是素数
    assert(isPrime(139)); // 139是素数
    assert(isPrime(149)); // 149是素数
    assert(isPrime(151)); // 151是素数
    assert(!isPrime(159)); // 159不是素数
    assert(!isPrime(161)); // 161不是素数
    assert(isPrime(163)); // 163是素数
    assert(!isPrime(165)); // 165不是素数
    assert(isPrime(167)); // 167是素数
    assert(isPrime(173)); // 173是素数
    assert(isPrime(179)); // 179是素数
    assert(isPrime(181)); // 181是素数
    assert(isPrime(191)); // 191是素数
    assert(isPrime(193)); // 193是素数
    assert(isPrime(197)); // 197是素数
    assert(isPrime(199)); // 199是素数

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}