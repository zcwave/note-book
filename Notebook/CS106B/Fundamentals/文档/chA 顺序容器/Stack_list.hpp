#pragma once

#include <stdexcept>
template <typename ValueType>
class Stack {
public:
    Stack(): head_(nullptr), count_(0) {}
    ~Stack(){ clear();}

    int size() const {
        return count_;
    }
    bool isEmpty() const {
        return count_ == 0;
    }
    void clear() {
        while (count_ > 0) {
            pop();
        }
    }

    // Usage: stack.push(value);
    void push(const ValueType &value) {
        Cell *cp = new Cell(value, cp);
        head_ = cp;
        count_++;
    }

/* Usage: ValueType top = stack.pop();
返回栈顶元素，并且删除它，
如果在空堆栈上调用此方法，则打印错误信息。 */
    ValueType pop() { 
        if (isEmpty()) {
            throw std::runtime_error("pop: Attempting to pop an empty stack");
        }

        Cell *old_head = head_;

        ValueType result = old_head->data;
        head_ = head_->link;

        delete old_head;
        count_--;

        return result;
    }

/* Usage: ValueType top = stack.peek();
返回栈顶元素的值，但不删除它。
如果在空堆栈上调用此方法，则打印错误信息。  */
    ValueType peek() {
        if (isEmpty())
            throw std::runtime_error("pop: Attempting to pop an empty stack");
        return head_->data;
    }


private:    
    struct Cell {
        Cell(ValueType val, Cell *cp) : data(val), link(cp) {}
        ValueType data;
        Cell *link;
    };
/*     成员变量       */
    Cell *head_; //链表的头节点,指向栈底
    int count_;  // 当前栈中元素的个数
    
/* 私有方法，用于类的实现 */
    void deepCopy(const Stack<ValueType> & src) {
        this->count_ = src.count_;
        if (src.isEmpty()) {
            clear(); // 这个实现不一定对?
            // 如果是拷贝赋值，会复数调用clear。
            return;
        }
        Cell *dst_list = nullptr;
        for (Cell *cp = src.head_->link;cp != nullptr; cp = cp->link) {
            Cell *ncp = new Cell(cp->data, nullptr);

            if (dst_list == nullptr) {
                head_ = ncp;
            } else {
                dst_list->link = ncp;
            }
            dst_list = ncp;
        }
    }

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
private:
    Stack(const Stack<ValueType> & src) {
        deepCopy(src);
    }
    Stack<ValueType> & operator=(const Stack<ValueType> & src) {
        if (this != &src) {
            clear();
            deepCopy(src);
        }
        return *this;
    }
};