#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int row = dungeon.size();
    int col = dungeon[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));
    dp[row][col - 1] = 1;
    dp[row - 1][col] = 1;
    for (int i = row - 1; i >= 0; i--) {
      for (int j = col - 1; j >= 0; j--) {
        int tmp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = max(tmp, 1);
      }
    }
    return dp[0][0];
  }
};

int main(int argc, char *argv[]) { return 0; }
