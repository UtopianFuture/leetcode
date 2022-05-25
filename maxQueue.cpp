#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class MaxQueue {
private:
  vector<int> q;

public:
  MaxQueue() {}

  int max_value() {
    int res = -1;
    for (int i = 0; i < (int)q.size(); i++) {
      res = max(res, q[i]);
    }
    return res;
  }

  void push_back(int value) { q.push_back(value); }

  int pop_front() {
    if (q.empty()) {
      return -1;
    }
    int res;
    res = q.front();
    q.erase(q.begin(), q.begin() + 1);
    // this first element in max_q is -1.
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
