#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__

#include <queue>

template<typename ValueType, typename PriorityType>
class PriorityQueue{
    using Pair = std::pair<ValueType, PriorityType>;
    using Container = std::priority_queue<Pair, std::vector<Pair>, std::greater<>>;
private:
    Container c_;
public:
    void enqueue(ValueType & value, PriorityType priority) {
        c_.push(std::make_pair(value, priority));
    }
    ValueType dequeue(){
        ValueType res = c_.top().first;
        c_.pop();
        return res;
    }
    [[nodiscard]] bool isEmpty() const{
        return c_.empty();
    };
};


#endif // __PRIORITY_QUEUE__ 