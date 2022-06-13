#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
  vector<int> res;
  int position;

public:
  void preorder(vector<NestedInteger> list) {
    for (auto l : list) {
      if (l.isInteger()) {
        res.push_back(l.getInteger());
      } else {
        preorder(l.getList());
      }
    }
  }

  NestedIterator(vector<NestedInteger> &nestedList) {
    this->position = 0;
    preorder(nestedList);
  }

  int next() { return res[position++]; }

  bool hasNext() { return position != (int)res.size(); }
};

int main(int argc, char *argv[]) { return 0; }
