#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class MinStack {
private:
  vector<int> min_stack;
  vector<int> stack;

public:
  /** initialize your data structure here. */
  MinStack() { min_stack.push_back(INT_MAX); }

  void push(int x) {
    stack.push_back(x);
    if (x < min_stack.back()) {
      min_stack.push_back(x);
    } else {
      min_stack.push_back(min_stack.back());
    }
  }

  void pop() {
    stack.pop_back();
    min_stack.pop_back();
  }

  int top() { return stack.back(); }

  int min() { return min_stack.back(); }
};

int main(int argc, char *argv[]) {
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  // obj->pop();
  // int param_3 = obj->top();
  int param_4 = obj->min();
  cout << param_4 << "\n";
  obj->pop();
  int param_5 = obj->top();
  cout << param_5 << "\n";
  int param_6 = obj->min();
  cout << param_6 << "\n";
  return 0;
}
