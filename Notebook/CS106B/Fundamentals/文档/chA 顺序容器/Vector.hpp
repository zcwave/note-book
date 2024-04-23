#pragma once
#include <initializer_list>
#include <stdexcept>
#include <sstream>


template<typename ValueType>
class Vector {

public:
    
    Vector() : count_(0), capacity_(INITIAL_CAPACITY_){
        array_ = new ValueType[capacity_]();
    }

    Vector(int n, const ValueType& val) :   count_(n),
                                            capacity_(INITIAL_CAPACITY_ + n),
                                            array_(nullptr)
    {
        if (n < 0) {
            throw std::length_error("Attempting to create a vector "
                                                        "with a negative size");
        }
        array_ = new ValueType[capacity_]();

        for (int i = 0; i < size(); i++) {
            array_[i] = val;
        }
    }

    Vector(std::initializer_list<ValueType> l) : Vector(l.size(), 0) {
        int i = 0;
        for (const auto& value : l) {
            array_[i++] = value;
        }
    }

    ~Vector() {
        delete[] array_;
        array_ = nullptr;
    }

    Vector(const Vector<ValueType>& src) {
        deepCopy(src);
    }

    Vector<ValueType>& operator=(const Vector<ValueType>& src) {
        if (this != &src) {
            delete[] array_;
            deepCopy(src);
        }

        return *this;
    }

    class iterator {

    private:
        const Vector* vp_{};
        int index_{};

    public:

        iterator() = default;

        iterator(const Vector* vp, int index) : vp_(vp), index_(index) {}

        iterator(const iterator& it) : iterator(it.vp_, it.index_) {}


        iterator& operator++() noexcept {
            index_++;
            return *this;
        }

        iterator operator++(int) noexcept {
            iterator copy{ *this };
            operator++();
            return copy;
        }

        iterator& operator--() noexcept {
            index_--;
            return *this;
        }

        iterator operator--(int) noexcept {
            iterator copy{ *this };
            operator--();
            return copy;
        }

        bool operator==(const iterator& rhs) const noexcept  {
            return vp_ == rhs.vp_ && index_ == rhs.index_;
        }
        

        std::strong_ordering operator<=>(const iterator & rhs) const {
            if (vp_ != rhs.vp_) throw std::logic_error("Iterators are in "
                                                        "different vectors");
            return index_ <=> rhs.index_;
        }

        // bool operator!=(const iterator& rhs) noexcept {
        //     return !(*this == rhs);
        // }

        // bool operator<(const iterator& rhs) {
        //     if (vp_ != rhs.vp_) 
        //         throw std::logic_error("Iterators are in different "
        //                                                           "vectors");
        //     return index_ < rhs.index_;
        // }

        // bool operator<=(const iterator& rhs) {
        //     if (vp_ != rhs.vp_) 
        //         throw std::logic_error("Iterators are in different "
        //                                                           "vectors");            
        //     return index_ <= rhs.index_;
        // }

        // bool operator>(const iterator& rhs) {
        //     if (vp_ != rhs.vp_) 
        //         throw std::logic_error("Iterators are in different "
        //                                                           "vectors");
        //     return index_ > rhs.index_;
        // }

        // bool operator>=(const iterator& rhs) {
        //     if (vp_ != rhs.vp_) 
        //         throw std::logic_error("Iterators are in different "
        //                                                           "vectors");
        //     return index_ >= rhs.index_;
        // }

        iterator operator+(const int& rhs) {
            return iterator(vp_, index_ + rhs);
        }

        iterator operator+=(const int& rhs) {
            index_ += rhs;
            return *this;
        }

        iterator operator-(const int& rhs) {
            return iterator(vp_, index_ - rhs);
        }

        iterator operator-=(const int& rhs) {
            index_ -= rhs;
            return *this;
        }

        int operator-(const iterator& rhs) {
            if (vp_ != rhs.vp_) 
                throw std::logic_error("Iterators are in different "
                                                                    "vectors");
            return index_ - rhs.index_;
        }

        ValueType& operator*() {
            return vp_->array_[index_];
        }

        ValueType* operator->() {
            return &vp_->array_[index_];
        }

        ValueType& operator[](int k) {
            return vp_->array_[index_ + k];
        }

    };

    iterator begin() const {
        return iterator(this, 0);
    }

    iterator end() const {
        return iterator(this, count_);
    }

public:
    int size() const {
        return count_;
    }
    bool isEmpty() const {
        return count_ == 0;
    }
    void clear() {
        count_ = 0;
    }

    ValueType get(int idx) const {
        // idx must be greater than zero.
        if (idx < size() && idx >= 0) {
            return array_[idx];
        }

        throw std::out_of_range("GET: Vector index out of bounded.");
    }

    void set(int idx, const ValueType& val) {
        /* Set not expand capacity */
        if (idx < size() && idx >= 0) {
            array_[idx] = val;
            return;
        }

        throw std::out_of_range("SET: Vector index out of bounded.");
    }

    void insert(int idx, const ValueType& val) {

        if (idx <= size() && idx >= 0) {

            if (size() == capacity_) {
                expandCapacity();
            }

            for (int i = size(); i > idx; i--) {
                array_[i] = array_[i - 1];
            }

            array_[idx] = val;
            count_++;

            return;
        }

        throw std::out_of_range("INSERT: Vector index out of bounded.");
    }

    void remove(int idx) {

        if (idx < size() && idx >= 0) {

            for (int i = idx; i < size() - 1; i++) {
                /* 'i < size() - 1' instead of 'i < size()'
                   The reason is that [size()] is the element to
                   be removed.
                */
                array_[i] = array_[i + 1];
            }

            count_--; // array[idx] is being marked as an invalid value.
            return;
        }

        throw std::out_of_range("REMOVE: Vector index out of bounded.");
    }

    void add(const ValueType& val) {
        insert(size(), val);
    }

    ValueType& operator[](int idx) {
        return array_[idx];
    }

    ValueType& at(int idx) {

        if (idx < size() && idx >= 0) {
            return array_[idx];
        }

        throw std::out_of_range("AT: Vector index out of bounded.");
    }


    size_t location(const ValueType& val, bool is_sorted = false);


    void sort() {
        sort(0, size() - 1);
    }
    
    std::string toString() {
        std::ostringstream os;
        os << "{";
        for (int i = 0; i < size(); i++) {
            if (i > 0) os << ", ";
            os << array_[i];
        }
        os << "}";
        return os.str();
    }


private:

    static const size_t INITIAL_CAPACITY_ = 16;
    static const int M = 10;

    /* Instance variables */
    ValueType* array_; /* A dynamic array of the elements */
    int count_{};     /* The allocated size of the array */
    int capacity_{};  /* The number of elements in use   */
    

    void sort(int lo, int hi) {
        if (hi <= lo + M) return insertSort();
        int j = partition(lo, hi);
        sort(lo, j - 1);
        sort(j + 1, hi);
    }

    void insertSort() {
        for (int i = 0; i < size(); i++) {
            for (int j = i; j > 0 && array_[j] < array_[j - 1]; j--) {
                std::swap(array_[j], array_[j - 1]);
            }
        }
    }

    decltype(auto) partition(int lo, int hi) {
        int i = lo;
        int j = hi + 1;

        auto value = array_[lo];

        while (i <= j) {
            while (array_[++i] < value && i != hi)
                ;
            while (array_[--j] > value && j != lo)
                ;
            std::swap(array_[i], array_[j]);
        }
        std::swap(array_[j], array_[lo]);
        return j;
    }

    /* Private method prototypes */
    void deepCopy(const Vector<ValueType>& src) {
        capacity_ = src.size() + INITIAL_CAPACITY_;
        this->array_ = new ValueType[capacity_];


        for (int i = 0; i < src.count_; i++) {
            array_[i] = src.array_[i];
        }

        // std::memcpy(array_, src.array_, src.count_ * sizeof(ValueType));
        count_ = src.count_;
    }

    void expandCapacity() {
        ValueType* old_array = array_;
        capacity_ *= 2;

        array_ = new ValueType[capacity_];
        // () 会触发构造函数，也就是会将内存初始化成默认值。

        // for (int i = 0; i < count_; i++) {
        //     array_[i] = old_array[i];
        // }

        std::memcpy(array_, old_array, count_ * sizeof(ValueType));

        delete[] old_array;
    }


};