// Copyright 2021 NNTU-CS
#include <string>
#include <climits>
#include "tstack.h"
int prec(char c) {
    if (c == '*' || c == '/') {
        return 3;
    }
    if (c == '+' || c == '-') {
        return 4;
    }
    if (c == '&') {
        return 8;
    }
    if (c == '^') {
        return 9;
    }
    if (c == '|') {
        return 10;
    }
    return INT_MAX;
}
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> s;
    std::string postfix;
    for (char c : inf) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (s.top() != '(') {
                postfix.push_back(s.top());
                postfix.push_back(' ');
                s.pop();
            }
            s.pop();
        } else if (isOperand(c)) {
            postfix.push_back(c);
            postfix.push_back(' ');
        } else {
            while (!s.isEmpty() && prec(c) >= prec(s.top())) {
                postfix.push_back(s.top());
                postfix.push_back(' ');
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}
int eval(std::string post) {
    TStack<int, 100> stack;
    for (char c : post) {
        if (c >= '0' && c <= '9') {
            stack.push(c - '0');
        } else {
            int x = stack.top();
            stack.pop();
            int y = stack.top();
            stack.pop();
            if (c == '+') {
                stack.push(y + x);
            } else if (c == '-') {
                stack.push(y - x);
            } else if (c == '*') {
                stack.push(y * x);
            } else if (c == '/') {
                stack.push(y / x);
            }
        }
    }
    return stack.top();
}
