#include <cassert>
#include <cstdlib>
#include <vector>
#include <cmath>

int roundToNearestInt(double x) {
    int sign = std::signbit(x) ? -1 : 1;
    x = std::abs(x);
    int res = x + 0.5;
    return sign * res;
}

int main() {
    std::vector<double> test_arr = {1.2, 4, 1.6, 1.4};
    std::vector<int>    vaild_arr = {1, 4, 2, 1};
    for (int i = 0; i < test_arr.size(); i++) {
        assert(vaild_arr[i] == roundToNearestInt(test_arr[i]));
    }
    return 0;
}