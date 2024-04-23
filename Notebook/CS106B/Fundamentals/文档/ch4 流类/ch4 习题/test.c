#include <stdio.h>

// 定义枚举类型 State
typedef enum {
    State1, // 第一种状态
    State2, // 第二种状态
    State3  // 第三种状态
} State;

int main() {
    // 声明一个枚举变量，并初始化为 State1
    State currentState = State1;

    // 使用 switch 语句处理枚举变量的不同值
    switch (currentState) {
        case State1:
            printf("Current state is State1.\n");
            break;
        case State2:
            printf("Current state is State2.\n");
            break;
        case State3:
            printf("Current state is State3.\n");
            break;
        default:
            printf("Unknown state.\n");
            break;
    }

    return 0;
}