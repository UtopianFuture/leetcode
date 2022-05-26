#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int sum = 0;
    int res = -1;
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }

    int tmp = 0;
    bool has = false;
    for (int i = 0; i < n; i++) {
      tmp += nums[i];
      if ((sum - nums[i]) & 1) {
        continue;
      } else {
        if (tmp - nums[i] == (sum - nums[i]) >> 1) {
          res = i;
          has = true;
          break;
        }
      }
    }
    if (has) {
      return res;
    } else {
      return -1;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
