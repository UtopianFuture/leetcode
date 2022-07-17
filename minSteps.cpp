#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minSteps(int n) {
    int paste = 0;
    vector<int> dp(n + 1, 0);
    dp[2] = 2;
    paste = 1;
    for (int i = 3; i <= n; i++) {
      if (i % 2) {
        dp[i] = dp[i - paste] + 1;
      } else {
        if (dp[i / 2] + 2 > dp[i - paste] + 1) {
          dp[i] = dp[i - paste] + 1;
        } else {
          dp[i] = dp[i / 2] + 2;
          paste = i / 2;
        }
      }
    }
    return dp[n];
  }
};

class Solution1 {
public:
  int dfs(int len, int paste, int times, int n) {
    if (len == n) {
      return times;
    }
    if (len > n) {
      return INT_MAX;
    }

    return min(dfs(len + paste, paste, times + 1, n),
               dfs(len * 2, len, times + 2, n));
  }

  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }
    return dfs(1, 1, 1, n);
  }
};

int main(int argc, char *argv[]) { return 0; }
