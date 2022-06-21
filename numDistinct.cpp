#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size();
    int n = t.size();
    if (n > m) {
      return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++) {
      dp[0][i] = 1;
    }
    for (int i = 1; i <= m && i <= n; i++) {
      if (s[i - 1] == t[i - 1]) {
        dp[i][i] = 1;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= m; j++) {
        if (s[j - 1] == t[i - 1]) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[n][m];
  }
};
int main(int argc, char *argv[]) { return 0; }
