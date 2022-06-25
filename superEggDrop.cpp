#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int superEggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
      dp[0][i] = 0;
      dp[1][i] = i;
    }
    for (int i = 1; i <= k; i++) {
      dp[i][0] = 0;
      dp[i][1] = 1;
    }

    for (int i = 2; i <= k; i++) {
      for (int j = 2; j <= n; j++) {
        int tmp;
        for (int x = 1; x < j; x++) {
          tmp = max(dp[i - 1][x - 1], dp[i][j - x]) + 1;
          dp[i][j] = min(dp[i][j], tmp);
        }
      }
    }
    return dp[k][n];
  }
};

class Solution1 {
public:
  int superEggDrop(int k, int n) {
    if (n == 1) {
      return 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= k; i++) {
      dp[1][i] = 1;
    }

    int res = -1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1;
      }
      if (dp[i][k] >= n) {
        res = i;
        break;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int k, n;
  cin >> k >> n;

  Solution1 *s = new Solution1;
  cout << s->superEggDrop(k, n) << endl;
  return 0;
}
