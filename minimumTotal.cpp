#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int row = triangle.size();
    int col = triangle[row - 1].size();
    if (row == 1) {
      return triangle[0][0];
    }
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = triangle[0][0];

    int res = INT_MAX;
    int tmp1 = INT_MAX, tmp2 = INT_MAX;
    for (int i = 1; i < row; i++) {
      for (int j = 0; j <= i; j++) {
        if (j - 1 >= 0) {
          tmp1 = dp[i - 1][j - 1] + triangle[i][j];
        }
        if (j != i) {
          tmp2 = dp[i - 1][j] + triangle[i][j];
        }
        dp[i][j] = min(tmp1, tmp2);
        tmp1 = INT_MAX;
        tmp2 = INT_MAX;
        if (i == row - 1) {
          res = min(res, dp[i][j]);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
