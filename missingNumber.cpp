#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = (int)nums.size();
    int tmp = 2 * n;
    for (int i = 0; i < n; i++) {
      if (nums[i] == n) {
        continue;
      }
      if (nums[i] > n) {
        nums[nums[i] - tmp] += tmp;
      } else {
        nums[nums[i]] += tmp;
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] < tmp) {
        return i;
      }
    }
    return n;
  }
};

class Solution1 {
public:
  int missingNumber(vector<int> &nums) {
    int n = (int)nums.size();
    int res = n;
    for (int i = 0; i < n; i++) {
      res ^= i ^ nums[i];
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
