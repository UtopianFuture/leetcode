#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    int m = INT_MAX;
    int tmp;
    for (int i = 1; i <= n; i++) {
      m = INT_MAX;
      tmp = sqrt(i);
      for (int j = 1; j <= tmp; j++) {
        m = min(m, dp[i - j * j]);
      }
      dp[i] = m + 1;
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) { return 0; }
