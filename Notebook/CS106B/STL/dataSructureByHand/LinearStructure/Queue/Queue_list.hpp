#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__

#include <cstdio>

template <typename ValueType>
class Queue
{
public:
    Queue():head_(nullptr), tail_(nullptr), count_(0){}
    ~Queue(){
        clear();
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

    struct Cell
    {
        ValueType data_;
        Cell *link_;
    };
    
/* 成员变量 */
    int count_;        // 当前队列元素个数  
    Cell *head_;       // 队列头部索引    
    Cell *tail_;       // 队列尾部索引值   

    
/* 私有方法，用于类的实现 */
    void deepCopy(const Queue<ValueType> & src);

/*  Copy constructor and assignment operator,
    These methods implement if stack needs deep copying */
public:
    Queue(const Queue<ValueType> & src);
    Queue<ValueType> & operator=(const Queue<ValueType> & src);
};

void error(char *str){
    printf("%s\n", str);
}


#endif // __QUEUE_LIST_H__