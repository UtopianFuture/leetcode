#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> dp;
  vector<vector<bool>> isVisited;
  int n;

public:
  bool isValid(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
  }

  int calculate(vector<vector<int>> matrix, int row, int col) {
    if (!isValid(row, col)) {
      return INT_MAX;
    }

    if (row == 0) {
      dp[0][col] = matrix[0][col];
      return matrix[0][col];
    }
    if (dp[row][col] != 100000) {
      return dp[row][col];
    }
    return dp[row][col] =
               matrix[row][col] + min(calculate(matrix, row - 1, col - 1),
                                      min(calculate(matrix, row - 1, col),
                                          calculate(matrix, row - 1, col + 1)));
  }

  void calculate1(vector<vector<int>> matrix, int row, int col) {
    if (!isValid(row, col)) {
      return;
    }

    if (isValid(row + 1, col - 1)) {
      if (isVisited[row + 1][col - 1]) {
        dp[row + 1][col - 1] =
            min(dp[row][col] + matrix[row + 1][col - 1], dp[row + 1][col - 1]);
      } else {
        isVisited[row + 1][col - 1] = 1;
        dp[row + 1][col - 1] = dp[row][col] + matrix[row + 1][col - 1];
      }
      calculate(matrix, row + 1, col - 1);
    }
    if (isValid(row + 1, col)) {
      if (isVisited[row + 1][col]) {
        dp[row + 1][col] =
            min(dp[row][col] + matrix[row + 1][col], dp[row + 1][col]);
      } else {
        isVisited[row + 1][col] = 1;
        dp[row + 1][col] = dp[row][col] + matrix[row + 1][col];
      }
      calculate(matrix, row + 1, col);
    }
    if (isValid(row + 1, col + 1)) {
      if (isVisited[row + 1][col + 1]) {
        dp[row + 1][col + 1] =
            min(dp[row][col] + matrix[row + 1][col + 1], dp[row + 1][col + 1]);
      } else {
        isVisited[row + 1][col + 1] = 1;
        dp[row + 1][col + 1] = dp[row][col] + matrix[row + 1][col + 1];
      }
      calculate(matrix, row + 1, col + 1);
    }
  }

  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    this->n = n;
    this->dp.resize(n, vector<int>(n, 100000));
    isVisited.resize(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[0][i] = matrix[0][i];
      isVisited[0][i] = 1;
    }

    for (int i = 0; i < n; i++) {
      calculate(matrix, n - 1, i);
    }

    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
      res = min(res, dp[n - 1][i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->minFallingPathSum(matrix) << endl;
  return 0;
}
