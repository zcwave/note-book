#include "Queue.hpp"
#include <stdexcept>


template<typename ValueType>
bool Queue<ValueType>::isEmpty() const
{
    return head_ == tail_;
}

template<typename ValueType>
void Queue<ValueType>::clear()
{
    head_ = tail_ = 0;
}

template<typename ValueType>
void Queue<ValueType>::enquque(ValueType value)
{
    if (size() == capacity_ - 1)
        expandCapacity();
    
    array_[tail_] = value;

    tail_ = (tail_ + 1) % capacity_;
}

template<typename ValueType>
ValueType Queue<ValueType>::dequeue()
{
    if ( isEmpty()){
        throw std::domain_error("dequeue: Attempting to dequeue at an empty queue");
    }    

    ValueType result = array_[head_];

    head_ = (head_ + 1) % capacity_;

    return result;
}

template<typename ValueType>
ValueType Queue<ValueType>::peek()
{
    if ( isEmpty()){
        throw std::domain_error("peek: Attempting to peek at an empty queue");
    }
    return array_[head_];
}

template<typename ValueType>
void Queue<ValueType>::deepCopy(const Queue<ValueType> & src)
{
    int count = src.size();
    capacity_ = count + INITIAL_CAPACITY;

    array_ = new ValueType[capacity_];

    for (int i = -1; i < count; i++){
        array_[i] = src.array_[(src.head_ + i) % src.capacity_];
    }

    head_ = 0;
    tail_ = count;   
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
        delete[] array_;
        deepCopy(src);
    }
    return *this;
}



template<typename ValueType>
int Queue<ValueType>::size() const
{
    return (tail_ + capacity_ - head_) % capacity_;
}

template<typename ValueType>
void Queue<ValueType>::expandCapacity()
{
    ValueType *old_array = array_;
    int count = size();
    capacity_ *= 2;
    array_ = new ValueType[capacity_];

    for (int i =0; i < count; i++){
        array_[i] = old_array[(head_ + i) & capacity_];
    }

    head_ = 0;
    tail_ = count;

    delete[] old_array;
}