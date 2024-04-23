#include <iostream>
#include <memory>

using namespace std;

void uniquePtrExample(){
    unique_ptr<int> p {new int()};
    *p = 15;
    cout << "address :" << &p << endl;
    cout << "data :" << *p << endl;

    // 可以用类似RAII的方式初始化

    // API get() 会获得被存储的原始指针
    cout << p.get() << endl;
    int *g = p.get();
    cout << g << endl;

    // API : 获取原始指针，并且销毁智能指针
}

void showPtr(shared_ptr<int> p) {
    *p = 15;
    cout << "data: " << *p << endl;
    cout << "calling time." << endl;
    cout << "Refering Count : " << p.use_count() << endl;
}

void sharePtrExample() {
    shared_ptr<int> p {new int()};
    cout << "calling before." << endl;
    cout << "Refering Count : " << p.use_count() << endl;
    showPtr(p);
    cout << "calling after." << endl;
    cout << "Refering Count : " << p.use_count() << endl;

}
int main() {
    sharePtrExample();
    return 0;
}