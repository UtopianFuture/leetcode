#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<int> nums;
  int used = 0;

public:
  bool backtrace(int k, int bucket, int target) {
    if (k == 0) {
      return true;
    }
    if (bucket == target) {
      return backtrace(k - 1, 0, target);
    }

    for (int i = 0; i < (int)nums.size(); i++) {
      if (used & (1 << i)) { // this number has been used
        continue;
      }
      if (bucket + nums[i] > target) {
        continue;
      }
      bucket += nums[i];
      used |= (1 << i);
      if (backtrace(k, bucket, target)) {
        return true;
      }
      used ^= (1 << i);
      bucket -= nums[i];
    }
    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    this->nums = nums;
    int n = (int)nums.size();
    if (n < k) {
      return false;
    }
    int sum = 0, target = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }
    if (sum % k) {
      return false;
    }
    target = sum / k;

    return backtrace(k, 0, target);
  }
};

int main(int argc, char *argv[]) { return 0; }
