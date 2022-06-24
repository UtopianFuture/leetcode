#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return true;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
    for (int i = 0; i < n; i++) {
      dp[i][i][0] = nums[i];
      dp[i][i][1] = 0;
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        int left = nums[i] + dp[i + 1][j][1];
        int right = nums[j] + dp[i][j - 1][1];
        if (left > right) {
          dp[i][j][0] = left;
          dp[i][j][1] = dp[i + 1][j][0];
        } else {
          dp[i][j][0] = right;
          dp[i][j][1] = dp[i][j - 1][0];
        }
      }
    }
    return dp[0][n - 1][0] >= dp[0][n - 1][1];
  }
};

int main(int argc, char *argv[]) { return 0; }
