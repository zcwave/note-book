#include "Stack.hpp"
#include <stdexcept>

template<typename value_type>
Stack<value_type>::Stack()
{
    capacity_ = INITIAL_CAPACITY_;
    array_ = new value_type[capacity_];
    count_ = 0;
}

template<typename value_type>
Stack<value_type>::~Stack()
{
    delete[] array_;
}

template<typename value_type>
int Stack<value_type>::size() const
{
    return count_; 
}

template<typename value_type>
bool Stack<value_type>::isEmpty() const
{
    return count_ == 0; 
}

template<typename value_type>
void Stack<value_type>::clear()
{
    count_ = 0;
}

template<typename value_type>
void Stack<value_type>::push(value_type value)
{
    if (count_ == capacity_)
        expandCapacity();
    array_[count_++] = value;
}

template<typename value_type>
value_type Stack<value_type>::pop()
{
    if (isEmpty())
        throw std::domain_error("pop: Attempting to pop an empty stack");
    return array_[--count_];
}

template<typename value_type>
value_type Stack<value_type>::peek()
{
    if (isEmpty())
        throw std::domain_error("pop: Attempting to pop an empty stack");
    return array_[count_ - 1];
}

template<typename value_type>
void Stack<value_type>::deepCopy(const Stack<value_type> & src)
{
    capacity_ = src.count_ + INITIAL_CAPACITY_;
    this->array_ = new value_type[capacity_];

    for (int i = 0; i < src.count_; i++){
        this->array_[i] = src.array_[i];
    }
    this->count_ = src.count_;
}

template<typename value_type>
void Stack<value_type>::expandCapacity()
{
    value_type *old_array = array_;
    capacity_ *= 2;

    array_ = new value_type[capacity_];

    for (int i =0; i < count_; i++){
        array_[i] = old_array[i];
    }

    delete[] old_array;
}

template<typename value_type>
Stack<value_type>::Stack(const Stack<value_type> & src)
{
    deepCopy(src);
}

template<typename value_type>
Stack<value_type> & 
    Stack<value_type>::operator=(const Stack<value_type> & src){

        if (this != &src){
            delete[] array_;
            deepCopy(src);
        }
    return *this;
}