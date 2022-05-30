#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class MovingAverage {
private:
  int size;
  int sum;
  vector<int> window;

public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    this->size = size;
    this->sum = 0;
  }

  double next(int val) {
    if ((int)window.size() < size) {
      window.push_back(val);
      sum += val;
      return 1.0 * sum / (int)window.size();
    } else {
      sum -= (int)window.front();
      window.erase(window.begin(), window.begin() + 1);
      window.push_back(val);
      sum += val;
      return 1.0 * sum / size;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
