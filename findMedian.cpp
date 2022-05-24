#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class MedianFinder {
private:
  // store the less numbers, the top is the largest in this region.
  priority_queue<int, vector<int>, less<int>> max_q;
  // store the greater numbers, the top is the smallest in this region.
  priority_queue<int, vector<int>, greater<int>> min_q;

public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (max_q.size() == min_q.size()) {
      min_q.push(num);
      int tmp = min_q.top();
      min_q.pop();
      max_q.push(tmp);
    } else {
      max_q.push(num);
      int tmp = max_q.top();
      max_q.pop();
      min_q.push(tmp);
    }
  }

  double findMedian() {
    if (max_q.size() == min_q.size()) {
      return (max_q.top() + min_q.top()) * 1.0 / 2;
    } else {
      return max_q.top() * 1.0;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
