#pragma once
#include <string>
int hashCode(const std::string &str);


class StringMap {

public:
    StringMap() : n_buckets_(INITIAL_BUCKET_COUNT) {
        buckets_ = new Cell*[n_buckets_]();

        for (int i = 0; i < n_buckets_; i++) {
            buckets_[i] = nullptr;
            // must?
        }
    }

    ~StringMap() {
        for (int i = 0; i < n_buckets_; i++) {
            Cell *cp = buckets_[i];

            while (cp != nullptr) {
                Cell *old_cell = cp;
                cp = cp->link;
                delete old_cell;
            }
        }

        delete buckets_; // must?
    }


    std::string get(const std::string &key) {
       int bucket = hashCode(key) % n_buckets_;  // 计算出key所在的桶的位置。
       Cell *cp = findCell(bucket, key);  // 查找key是否在桶内。
       return (cp == nullptr) ? "error" : cp->value;  // 找不到，返回空字符串
    }

    void put(const std::string &key, const std::string &value) {
        int bucket = hashCode(key) % n_buckets_;  // 计算出key所在的桶的位置。
        Cell *cp = findCell(bucket, key);  // 查找key是否在桶内。

        if (cp == nullptr) {
            cp = new Cell(key, value, buckets_[bucket]);
        } else {
            cp->value = value;
        }
    }

    // int size() const {}
    // bool isEmpty() const {}
    // bool containsKey(const std::string &key) {}
    // void remove(const std::string &key) {}
    // void clear(){}
private:

    struct Cell {
        Cell() = delete;
        Cell(std::string k, std::string val, Cell *cp) : key(k), value(val), link(cp) {}
        std::string key;
        std::string value;
        Cell *link;
    };

    static const int INITIAL_BUCKET_COUNT = 13;
    Cell **buckets_;
    int n_buckets_;

    Cell *findCell(int bucket, const std::string &key) { 
        Cell *cp = buckets_[bucket];
        while (cp != nullptr && key != cp->key) {
            cp = cp->link;
        }
        return cp;
    }

    StringMap(const StringMap &src) {}
    StringMap & operator=(const StringMap &src) {
        return *this;
    }

};