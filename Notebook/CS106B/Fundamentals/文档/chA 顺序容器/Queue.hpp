#pragma once


#include <stdexcept>
template <typename ValueType>
class Queue
{
public:
    Queue():head_(0), tail_(0), capacity_(INITIAL_CAPACITY){
        array_ = new ValueType[INITIAL_CAPACITY]();
    }
    ~Queue(){
        delete[] array_;
    }

    int size() const {
        return (tail_ + capacity_ - head_) % capacity_;
    }
    bool isEmpty() const {
        return head_ == tail_;
    }
    void clear() {
        head_ = tail_ = 0;
    }

    // Usage: queue.enqueue(value);
    void enquque(const ValueType &value) {
        if (size() == capacity_ - 1)
            expandCapacity();
    
        array_[tail_] = value;
        tail_ = (tail_ + 1) % capacity_;
    }

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType dequeue() {
        if (isEmpty()){
            throw std::logic_error("DEQUEUE: Attempting to dequeue at an empty queue");
        }    

        ValueType result = array_[head_];
        head_ = (head_ + 1) % capacity_;
        return result;
    }

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType peek() {
        if (!isEmpty()){
            return array_[head_]; 
        }
        throw std::logic_error("PEEK: Attempting to peek at an empty queue");
    }



private:
    
    static const  int INITIAL_CAPACITY = 10;

/* 成员函数 */
    ValueType *array_; 
    int capacity_;   //  当前队列容量
    int head_;       // 队列头部索引    
    int tail_;       // 队列尾部索引值   

    
/* 私有方法，用于类的实现 */
    void deepCopy(const Queue<ValueType> & src) {
        int count = src.size();
        capacity_ = count + INITIAL_CAPACITY;

        array_ = new ValueType[capacity_];

        for (int i = -1; i < count; i++){
            array_[i] = src.array_[(src.head_ + i) % src.capacity_];
        }

        head_ = 0;
        tail_ = count;   
    }   

    void expandCapacity() {
        ValueType *old_array = array_;
        int count = size();
        capacity_ *= 2;
        array_ = new ValueType[capacity_];

        for (int i = 0; i < count; i++){
            array_[i] = old_array[(head_ + i) & capacity_];
        }

        head_ = 0;
        tail_ = count;

        delete[] old_array;
    }
/*  Copy constructor and assignment operator,
    These methods implement if queue needs deep copying */
public:

    Queue(const Queue<ValueType> & src) {
        deepCopy(src);
    }

    Queue<ValueType> & operator=(const Queue<ValueType> & src) {
        if (this != &src){
            delete[] array_;
            deepCopy(src);
        }
        return *this;
    }   
};

