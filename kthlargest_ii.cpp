#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> q;
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (auto &x : nums) {
      add(x);
    }
  }

  int add(int val) {
    q.push(val);
    if (q.size() > k) {
      q.pop();
    }
    return q.top();
  }
};

int main(int argc, char *argv[]) { return 0; }
