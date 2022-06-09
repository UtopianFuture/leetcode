#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> dp(n, 0);

    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }
