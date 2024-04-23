#pragma once

#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
template <typename ValueType>
class LinkedList {
public:
    using reference = ValueType &;
    using const_reference = const ValueType &;

    LinkedList() : head_(nullptr), tail_(nullptr), count_(0) {}
    ~LinkedList() { clear(); }

    bool isEmpty() const { 
        return head_ == nullptr;
        // return size() == 0;
    }

    size_t size() const {
        return count_;
    }

    void clear() {
        Cell *current = head_;
        while (current) {
            Cell *next = current->next;
            delete current;
            current = next;
        }

        head_ = tail_ = nullptr;
        count_ = 0;
    }

    reference front() {
        if (!isEmpty()) {
            return head_->data;
        }
        throw std::logic_error("The list is empty"); 
    }
    const_reference front() const {
        return LinkedList::front();
        // 明确调用非 const 版本的 front() 
    }

    void push_back(const ValueType &data) {
        Cell *new_cell = new Cell(data);
        if (isEmpty()) {
            head_ = new_cell;
            tail_ = new_cell;
        } else {
            new_cell->prev = tail_;
            tail_->next = new_cell;
            tail_ = new_cell;
        }
        count_++;
    }

    void push_front(const ValueType &data) {
        Cell *new_cell = new Cell(data);
        if (isEmpty()) {
            head_ = new_cell;
            tail_ = new_cell;
        } else {
            new_cell->next = head_;
            head_->prev = new_cell;
            head_ = new_cell;
        }
        count_++; 
    }

    ValueType pop_back() {
        if (isEmpty()) {
            throw std::logic_error("The list is empty");
        } else {
            Cell* old_tail = tail_;

            tail_ = tail_->prev;

            if (tail_ == nullptr) {
                head_ = nullptr;
            } else {
                tail_->next = nullptr;
            }

            auto data = old_tail->data;
            count_--; 
            delete old_tail;
            return data;
        }
    }

    ValueType pop_front() { 
        if (isEmpty()) {
            throw std::logic_error("The list is empty");
        } else {
            Cell* old_head = head_;

            head_ = head_->next;

            if (head_ == nullptr) {
                tail_ = nullptr;
            } else {
                head_->prev = nullptr;
            }

            auto data = old_head->data;
            count_--; 
            delete old_head;
            return data;
        }
    }

    [[deprecated("AT: This function is deprecated and should no longer be used." 
                 "Please use newFunction instead.")]]
    reference at(int index) const {
        // 一个O(n)的算法
        int ct = size();
        if (index >= 0 && index < size()) {
            if (ct > size() / 2) {
                Cell *current = tail_;
                while (ct--) {
                    current = current->prev;
                }
                return current->data;
            } else {
                Cell *current = head_;
                while (ct--) {
                    current = current->next;
                }
                return current->data;
            }
        }
        throw std::out_of_range("AT: out of range");
    }

    [[deprecated("SHOW_FORWARD: This function is deprecated and should no longer be used." 
                 "Please use newFunction instead.")]]
    void show_forward() {
        Cell *current = head_;
        while (current) {
            std::cout << current->data << "->";
            current = current->next;
        }
        std::cout << std::endl;
    }

    [[deprecated("SHOW_BACKWARD: This function is deprecated and should no longer be used." 
                 "Please use newFunction instead.")]]
    void show_backward() {
        Cell *current = tail_;
        while (current) {
            std::cout << current->data << "<-";
            current = current->prev;
        } 
        std::cout << std::endl;
    }

private:

    struct Cell {
        Cell() = delete;
        explicit Cell(ValueType val) : data(val), prev(nullptr), next(nullptr) {}
        ValueType data;
        Cell *prev;
        Cell *next;
    };

    Cell *head_;
    Cell *tail_;
    std::size_t count_;


};