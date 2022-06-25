#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> dp;

public:
  int dfs(int start, int n) {
    if (n <= start) {
      return 0;
    }

    if (dp[start][n]) {
      return dp[start][n];
    }

    int res = INT_MAX, cur;
    for (int i = start; i <= n; i++) {
      cur = max(dfs(start, i - 1), dfs(i + 1, n)) + i;
      res = min(res, cur);
    }
    dp[start][n] = res;
    return res;
  }

  int getMoneyAmount(int n) {
    if (n == 1) {
      return 0;
    }

    dp.resize(n + 1, vector<int>(n + 1));
    return dfs(1, n);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->getMoneyAmount(n) << endl;
  return 0;
}
