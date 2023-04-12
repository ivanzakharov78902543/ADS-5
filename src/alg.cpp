// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "Header.h"
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
    return (c >= '0' && c <= '9');
}
std::string infx2pstfx(std::string inf) {
    char probel = ' ';
    std::stack<char> s;
    std::string postfix;
    for (char c : inf) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (s.top() != '(') {
                postfix.push_back(s.top());
                postfix.push_back(probel);
                s.pop();
            }
            s.pop();
        } else if (isOperand(c)) {
            postfix.push_back(c);
            postfix.push_back(probel);
        } else {
            while (!s.empty() && prec(c) >= prec(s.top())) {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix.push_back(s.top() );
        s.pop();
    }
    return postfix;
}
int eval(std::string pref) {
    std::stack<int> stack;
    for (char c : pref) {
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
