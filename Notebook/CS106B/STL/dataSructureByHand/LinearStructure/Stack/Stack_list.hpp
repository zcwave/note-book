#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__

#include <cstdio>

template <typename value_type>
class Stack
{
public:
    Stack(): head_(nullptr), count_(0){}
    ~Stack(){clear();}

    int size() const;
    bool isEmpty() const;
    void clear();

    // Usage: stack.push(value);
    void push(value_type value);

/* Usage: value_type top = stack.pop();
返回栈顶元素，并且删除它，
如果在空堆栈上调用此方法，则打印错误信息。 */
    value_type pop();

/* Usage: value_type top = stack.peek();
返回栈顶元素的值，但不删除它。
如果在空堆栈上调用此方法，则打印错误信息。  */
    value_type peek();



private:


    struct Cell
    {
        value_type data_;
        Cell *link_;
    };

/*     成员变量       */
    Cell *head_; //链表的头节点
    int count_;  // 当前栈中元素的个数
    
/* 私有方法，用于类的实现 */
    void deepCopy(const Stack<value_type> & src);

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
public:
    Stack(const Stack<value_type> & src);
    Stack<value_type> & operator=(const Stack<value_type> & src);
};


#endif // __STACK_LIST_H__