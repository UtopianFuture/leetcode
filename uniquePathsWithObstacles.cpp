#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = (int)obstacleGrid.size();
    int n = (int)obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      if (obstacleGrid[0][i]) {
        for (int j = i + 1; j < n; j++) {
          obstacleGrid[0][j] = 1;
        }
        break;
      }
      dp[0][i] = 1;
    }

    for (int i = 0; i < m; i++) {
      if (obstacleGrid[i][0]) {
        for (int j = i + 1; j < m; j++) {
          obstacleGrid[j][0] = 1;
        }
        break;
      }
      dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j]) {
          dp[i][j] = 0;
          continue;
        }
        if (obstacleGrid[i][j - 1] && obstacleGrid[i - 1][j] == 0) {
          dp[i][j] = dp[i - 1][j];
        } else if (obstacleGrid[i - 1][j] && obstacleGrid[i][j - 1] == 0) {
          dp[i][j] = dp[i][j - 1];
        } else if (obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int m, n;
  cin >> m >> n;
  vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> obstacleGrid[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->uniquePathsWithObstacles(obstacleGrid) << endl;
  return 0;
}
