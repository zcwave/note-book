#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <cstdio>

template <typename ValueType>
class Queue
{
public:
    Queue():head_(0), tail_(0), capacity_(INITIAL_CAPACITY){
        array_ = new ValueType[INITIAL_CAPACITY];
    }
    ~Queue(){
        delete[] array_;
    }

    int size() const;
    bool isEmpty() const;
    void clear();

    // Usage: queue.enqueue(value);
    void enquque(ValueType value);

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType dequeue();

/* Usage: ValueType head = queue.dequeue();
返回队头元素，并且删除它，
如果在空队列上调用此方法，则打印错误信息。 */
    ValueType peek();



private:
    
    static const  int INITIAL_CAPACITY = 10;

/* 成员函数 */
    ValueType *array_; 
    int capacity_;   //  当前队列容量
    int head_;       // 队列头部索引    
    int tail_;       // 队列尾部索引值   

    
/* 私有方法，用于类的实现 */
    void deepCopy(const Queue<ValueType> & src);
    void expandCapacity();

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
public:
    Queue(const Queue<ValueType> & src);
    Queue<ValueType> & operator=(const Queue<ValueType> & src);
};

void error(char *str){
    printf("%s\n", str);
}


#endif // __QUEUE_H__