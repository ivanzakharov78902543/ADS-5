// Copyright 2021 NNTU-CS
#include <stack>
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  std::stack <T> stack;
};

#endif  // INCLUDE_TSTACK_H_
