#include "Queue_list.hpp"


template<typename ValueType>
bool Queue<ValueType>::isEmpty() const
{
    return count_ == 0;
}

template<typename ValueType>
void Queue<ValueType>::clear()
{
    while (count_ > 0)
    {
        dequeue();
    }
        
}

template<typename ValueType>
int Queue<ValueType>::size() const
{
    return count_;
}

template<typename ValueType>
void Queue<ValueType>::enquque(ValueType value)
{
    Cell *cp = new Cell();
    cp->data_ = value;
    cp->link_ = nullptr;

    if (head_ = nullptr){
        head_ = cp;
    }
    else {
        tail_->link_ = cp;
    }

    tail_ = cp;
    count_++;
}

template<typename ValueType>
ValueType Queue<ValueType>::dequeue()
{
    if ( isEmpty()){
        error("dequeue: Attempting to dequeue at an empty queue");
    }    

    Cell *old_head = head_;
    ValueType result = head_->data_;

    head_ = head_->link_;
    
    if (head_ == nullptr)
        tail_ = nullptr;

    delete old_head;
    count_--;
    return result;
}

template<typename ValueType>
ValueType Queue<ValueType>::peek()
{
    if ( isEmpty()){
        error("peek: Attempting to peek at an empty queue");
    }
    return head_->data_;
}

template<typename ValueType>
void Queue<ValueType>::deepCopy(const Queue<ValueType> & src)
{
    head_ = nullptr;
    tail_ = nullptr;
    count_ = 0;

    for (Cell *cp = src.head_; cp != nullptr; cp = cp->link_)
    {
        enquque(cp->data_);
    }
}

template<typename ValueType>
Queue<ValueType>::Queue(const Queue<ValueType> & src)
{
    deepCopy(src);
}

template<typename ValueType>
Queue<ValueType> & Queue<ValueType>::operator=(const Queue<ValueType> & src)
{
    if (this != &src){
        clear();
        deepCopy(src);
    }
    return *this;
}



