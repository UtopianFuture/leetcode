#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool oneEditAway(string first, string second) {
    int n = first.size();
    int m = second.size();
    if (n == 0 && n == m) {
      return true;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++) {
      dp[0][i] = i;
    }
    for (int i = 0; i <= n; i++) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (first[i - 1] == second[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
      }
    }
    return dp[n][m] <= 1;
  }
};

int main(int argc, char *argv[]) { return 0; }
