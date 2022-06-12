#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = (int)nums.size();
    int res = INT_MAX;
    vector<vector<long>> dp(n, vector<long>(n, 0));

    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
      if (dp[i][i] >= k) {
        return 1;
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = dp[i][j - 1] + nums[j];
        if (dp[i][j] >= k) {
          res = min(res, j - i + 1);
        }
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};

int main(int argc, char *argv[]) { return 0; }
