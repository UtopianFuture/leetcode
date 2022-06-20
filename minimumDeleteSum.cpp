#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n2; i++) {
      dp[0][i] = dp[0][i - 1] + s2[i - 1];
    }
    for (int i = 1; i <= n1; i++) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
      }
    }
    return dp[n1][n2];
  }
};

int main(int argc, char *argv[]) { return 0; }
