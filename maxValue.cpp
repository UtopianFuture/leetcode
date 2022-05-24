#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxValue(vector<vector<int>> &grid) {
    int r = (int)grid.size();
    int c = (int)grid[0].size();
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
      }
    }
    return dp[r][c];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int r, c;
  cin >> r >> c;
  vector<vector<int>> grid(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->maxValue(grid);
  return 0;
}
