
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

        while (true) {
            while (array_[++i] < value && i != hi)
                ;
            while (array_[--j] > value && j != lo)
                ;
            if (i >= j) break;
            std::swap(array_[i], array_[j]);
        }
        std::swap(array_[j], array_[lo]);
        return j;
    }
