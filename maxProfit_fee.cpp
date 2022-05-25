#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = (int)prices.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp_0(n, 0), dp_1(n, 0);
    dp_0[0] = 0;
    dp_1[0] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp_0[i] = max(dp_0[i - 1], dp_1[i - 1] + prices[i] - fee);
      dp_1[i] = max(dp_1[i - 1], dp_0[i - 1] - prices[i]);
    }
    return dp_0[n - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }
