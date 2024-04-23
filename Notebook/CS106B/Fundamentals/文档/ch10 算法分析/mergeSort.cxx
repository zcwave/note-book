#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>
template<typename ValueType>
void merge(std::vector<ValueType> &dest, std::vector<ValueType> &v1, std::vector<ValueType> &v2) {
    size_t n1 = v1.size();
    size_t n2 = v2.size();

    size_t p1 = 0;
    size_t p2 = 0;

    while (p1 < n1 && p2 < n2) {
        if (v1[p1] < v2[p2]) {
            dest.push_back(v1[p1++]);
        } else {
            dest.push_back(v2[p2++]);
        }
    }
    while (p1 < n1) {
        dest.push_back(v1[p1++]);
    }

    while (p2 < n2) {
        dest.push_back(v2[p2++]);
    }
}
template<typename ValueType>
void mergeSort(std::vector<ValueType> &vec) {
    size_t n = vec.size();
    if (n <= 1) {
        return;
    }

    std::vector<ValueType> v1, v2;

    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            v1.push_back(vec[i]);
        } else {
            v2.push_back(vec[i]);
        }
    }

    mergeSort<ValueType>(v1);
    mergeSort<ValueType>(v2);
    vec.clear();
    merge<ValueType>(vec, v1, v2);
}


int main(){
    std::vector<int> vi = {1, 23, 12, 2, 14};
    mergeSort(vi);
    for (auto x : vi) {
        std::cout << x << std::endl;
    }
}

int strlen(char *str) {
    char *cp;
    for (cp = str; *cp != '\0'; cp++);
    return cp - str;
}