#pragma once

#include <stdexcept>

template <typename ValueType>
class Queue
{
    using const_reference = const ValueType &;
public:

    Queue() : head_(nullptr), tail_(nullptr), count_(0){}
    ~Queue(){
        clear();
    }

    int size() const {
        return count_;
    }
    bool isEmpty() const {
        return count_ == 0;
    }

    void clear() {
        while (count_ > 0) {
            dequeue();
        }
    }

    // Usage: queue.enqueue(value);
    void enquque(const_reference value) {
        // 由于在更新链表tail 所以说这是尾插法。
        Cell *cp = new Cell(value, nullptr);

        if (head_ == nullptr) {
            head_ = cp;
        } else {
            tail_->link = cp;
        }

        tail_ = cp;
        count_++;
    }

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType dequeue() {
        if (isEmpty()) {
            throw std::logic_error("DEQUEUE: Attempting to dequeue at an empty queue");
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

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType peek() {
        if (isEmpty()) {
            throw std::logic_error("PEEK: Attempting to peek at an empty queue");
        }
        return  head_->data;
    }



private:

    struct Cell
    {
        Cell(ValueType val, Cell *lk): data(val), link(lk) {}
        ValueType data;
        Cell *link;
    };
    
/* 成员变量 */
    int count_;        // 当前队列元素个数  
    Cell *head_;       // 队列头部索引    
    Cell *tail_;       // 队列尾部索引值   

    
/* 私有方法，用于类的实现 */
    void deepCopy(const Queue<ValueType> & src) {
        head_ = tail_ = nullptr;
        count_ = 0;
        for (Cell *cp = src.head_; cp != nullptr; cp = cp->link_) {
            enquque(cp->data_);
        }
    }

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
public:
    Queue(const Queue<ValueType> & src) {
        deepCopy(src);
    }
    Queue<ValueType> & operator=(const Queue<ValueType> & src) {
        if (this != &src) {
            clear();
            deepCopy(src);
        }
        return *this;
    }
};
