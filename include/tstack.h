// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
template<typename T, int size>
class TStack {
 private:
    T arr[100];
    int m;

 public:
    TStack() : m(-1) {}
    void push(T value) {
        if (!isFull())
            arr[++m] = value;
        else
            throw std::string("Full");
    }
    T get() const {
        return arr[m];
    }
    T pop() {
        if (isEmpty())
            throw std::string("Empty");
        else
            return arr[m--];
    }
    bool isEmpty() const {
        return m == -1;
    }
    bool isFull() const {
        return m == size - 1;
    }
    T top() {
        if (!isEmpty()) {
            return arr[m];
        } else {
            exit(EXIT_FAILURE);
        }
    }
};
#endif  // INCLUDE_TSTACK_H_
