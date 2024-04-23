#pragma once
#include <stdexcept>

template <typename ValueType>
class Stack
{
public:
    Stack() : count_(0), capacity_(INITIAL_CAPACITY_) {
        array_ = new ValueType[capacity_]();
    }
    ~Stack() {
        delete [] array_;
    }

    int size() const {
        return count_;
    }
    bool isEmpty() const {
        return count_ == 0;
    }
    void clear() {
        count_ = 0;
    }

    // Usage: stack.push(value);
    void push(const ValueType &value) {
        if (size() == capacity_)
            expandCapacity();
        array_[count_++] = value;
    }

/* Usage: ValueType top = stack.pop();
返回栈顶元素，并且删除它，
如果在空堆栈上调用此方法，则打印错误信息。 */
    ValueType pop() {
        if (isEmpty())
            throw std::runtime_error("POP: Attempting to pop an empty stack");
        return array_[--count_];
    }

/* Usage: ValueType top = stack.peek();
返回栈顶元素的值，但不删除它。
如果在空堆栈上调用此方法，则打印错误信息。  */
    ValueType peek() {
        if (isEmpty())
            throw std::runtime_error("pop: Attempting to pop an empty stack");
        return array_[count_ - 1]; 
    }



private:
    
    static const int INITIAL_CAPACITY_ = 16;

/*     成员变量       */
    ValueType *array_;     //用于存放元素的动态数组
    int capacity_;          // 已经分配的数组大小
    int count_;             // 当前栈中元素的个数

/* 私有方法，用于类的实现 */
    void deepCopy(const Stack<ValueType> & src) {
        capacity_ = src.count_ + INITIAL_CAPACITY_;
        this->array_ = new ValueType[capacity_];

        // for (int i = 0; i < src.count_; i++){
        //     array_[i] = src.array_[i];
        // }
        memcpy(array_, src.array_, src.count_ * sizeof(ValueType));
        this->count_ = src.count_;
    }

    void expandCapacity() {
        ValueType *old_array = array_;
        capacity_ *= 2;
        array_ = new ValueType[capacity_]();
        std::memcpy(array_, old_array, count_ * sizeof(ValueType));
        delete [] old_array;
    }

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
private:

    Stack(const Stack<ValueType> & src) {
        deepCopy(src);
    }

    Stack<ValueType> & operator=(const Stack<ValueType> & src) {
        if (this != &src) {
            delete [] array_;
            deepCopy(src);
        }
        return *this;
    }
};