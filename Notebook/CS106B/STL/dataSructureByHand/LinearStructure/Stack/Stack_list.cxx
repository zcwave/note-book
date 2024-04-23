#include "Stack_list.hpp"
#include <stdexcept>


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
    while (count_ > 0){
        pop();
    }
}

template<typename value_type>
void Stack<value_type>::push(value_type value)
{
    Cell *cp = new Cell();
    cp->data_ = value;
    cp->link_ = head_;

    head_ = cp;
    count_++;
}

template<typename value_type>
value_type Stack<value_type>::pop()
{
    if (isEmpty())
        throw std::domain_error("pop: Attempting to pop an empty stack");

    Cell *old_head = head_;

    value_type result = cp->data_;
    head_ = head_->link_;
    count_--;

    delete old_head;
    return result;
}

template<typename value_type>
value_type Stack<value_type>::peek()
{
    if (isEmpty())
        throw std::domain_error("pop: Attempting to pop an empty stack");
    return head_->data_;
}

template<typename value_type>
void Stack<value_type>::deepCopy(const Stack<value_type> & src)
{
    this->count_ = src.count_;

    // construct new linked list

    Cell *tail = nullptr;
    Cell *cp = src.head_->link_;
    for (; cp != nullptr; cp = cp->link_){
        Cell *ncp = new Cell();
        ncp->data_ = cp->data_;

        if (tail == nullptr){
            head_ = ncp;
            // 头节点单独处理
        }
        else {
            tail->link_ = ncp;
            // 正常节点，按顺序拷贝
        }
        tail = ncp;
    }

    if (tail != nullptr){
        tail->link_ = nullptr;
    }
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
            clear();
            deepCopy(src);
        }
    return *this;
}