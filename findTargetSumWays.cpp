#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = (int)nums.size();
    int sum = 0, neg = 0;
    for (auto num : nums) {
      sum += num;
    }

    // (sum - neg) - neg = target -> neg = (sum - target) / 2,
    // if neg < 0, return 0; if (sum - target) % 2 == 1, return 0.
    if ((sum - target) % 2 || sum - target < 0) {
      return 0;
    }
    neg = (sum - target) / 2;

    // dp[i][j] present if there is a solution that choose some numbers
    // (include 0 number) from nums[0, i] and the sum is equal j.
    vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
    // dp base: choose 0 number and the sum is j
    // for (int i = 0; i <= neg; i++) {
    // dp[0][i] = 0;
    // }
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= neg; j++) {
        if (j < nums[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[n][neg];
  }
};

int main(int argc, char *argv[]) { return 0; }
