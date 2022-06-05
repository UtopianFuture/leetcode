#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int res = INT_MIN;
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < col; i++) {
      dp[0][i] = matrix[0][i] - '0';
      res = max(res, dp[0][i]);
    }

    for (int i = 0; i < row; i++) {
      dp[i][0] = matrix[i][0] - '0';
      res = max(res, dp[i][0]);
    }
    if (row == 1 || col == 1) {
      return res;
    }

    int tmp1, tmp2;
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][j] == '1') {
          tmp1 = min(dp[i - 1][j], dp[i][j - 1]);
          tmp2 = min(tmp1, dp[i - 1][j - 1]);
          tmp2 = sqrt(tmp2);
          dp[i][j] = (int)pow(tmp2 + 1, 2);
        } else {
          dp[i][j] = 0;
        }
        res = max(res, dp[i][j]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int row, col;
  cin >> row >> col;
  vector<vector<char>> dp(row, vector<char>(col, '0'));
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> dp[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->maximalSquare(dp) << endl;
  return 0;
}
