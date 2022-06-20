#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
      dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
      res = max(dp[i], res);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
