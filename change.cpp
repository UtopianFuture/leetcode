#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    sort(coins.begin(), coins.end(), less<int>());
    for (int i = 0; i <= amount; i++) {
      dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= amount; j++) {
        if (coins[i - 1] > j) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        }
      }
    }
    return dp[n][amount];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, amount;
  cin >> n >> amount;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  Solution *s = new Solution;
  cout << s->change(amount, coins) << endl;
  return 0;
}
