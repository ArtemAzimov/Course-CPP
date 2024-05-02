#include <iostream>
#include <vector>

using namespace std;

class MyIterator {
public:
    using value_type = int;
    using difference_type = int;
    using pointer = int*;
    using reference = int&;
    using iterator_category = bidirectional_iterator_tag;

    MyIterator(pointer ptr) : ptr_(ptr) {}
    MyIterator& operator++() {
        ++ptr_;
        return *this;
    }
    MyIterator operator++(int) {
        MyIterator temp(*this);
        ++ptr_;
        return temp;
    }
    MyIterator& operator--() {
        --ptr_;
        return *this;
    }
    MyIterator operator--(int) {
        MyIterator temp(*this);
        --ptr_;
        return temp;
    }
    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }
    bool operator==(const MyIterator& other) const { return ptr_ == other.ptr_; }
    bool operator!=(const MyIterator& other) const { return !(*this == other); }
private:
    pointer ptr_;
};

constexpr uint SIZE = 100;

class MyContainer {
public:
    using iterator = MyIterator;

    MyContainer() {}

    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + count_); }

    void push_back(int value) { data_[count_++] = value; }
    size_t size() const { return SIZE; }

    // iterator begin() { return iterator(data_.data()); }
    // iterator end() { return iterator(data_.data() + data_.size()); }

    // void push_back(int value) { data_.push_back(value); }
    // size_t size() const { return data_.size(); }
private:
    // vector<int> data_;
    int count_ = 0;
    int data_[SIZE];
};

int main() {
    MyContainer container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);

    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
