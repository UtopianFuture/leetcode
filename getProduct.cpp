#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class ProductOfNumbers {
private:
  vector<int> nums;
  vector<int> sum;

public:
  ProductOfNumbers() {}

  void add(int num) {
    nums.push_back(num);
    if (sum.empty()) {
      sum.push_back(num);
    } else {
      sum.push_back(sum[sum.size() - 1] * num);
    }
    if (num == 0) {
      sum.clear();
    }
  }

  int getProduct(int k) {
    int n = (int)sum.size();
    if (n < k) {
      return 0;
    }
    if (n == k) {
      return sum[n - 1];
    }
    return sum[n - 1] / sum[n - k - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }
