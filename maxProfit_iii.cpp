#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();
    int k = 2;
    vector<vector<int>> dp_0(n, vector<int>(k + 1, 0));
    vector<vector<int>> dp_1(n, vector<int>(k + 1, 0));

    for (int i = 0; i <= k; i++) {
      dp_0[0][i] = 0;
      dp_1[0][i] = -prices[0];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= k; j++) {
        dp_0[i][j] = max(dp_0[i - 1][j], dp_1[i - 1][j] + prices[i]);
        dp_1[i][j] = max(dp_1[i - 1][j], dp_0[i - 1][j - 1] - prices[i]);
      }
    }
    return dp_0[n - 1][k];
  }
};

int main(int argc, char *argv[]) { return 0; }
