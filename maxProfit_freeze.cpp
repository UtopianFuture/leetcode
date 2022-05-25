#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();
    if (n == 0 || n == 1) {
      return 0;
    }

    int k = 2;
    vector<int> dp_0(n, 0);
    vector<int> dp_1(n, 0);

    dp_0[0] = 0;
    dp_1[0] = -prices[0];
    dp_0[1] = max(dp_0[0], dp_1[0] + prices[1]);
    dp_1[1] = max(-prices[0], -prices[1]);
    for (int i = 2; i < n; i++) {
      dp_0[i] = max(dp_0[i - 1], dp_1[i - 1] + prices[i]);
      dp_1[i] = max(dp_1[i - 1], dp_0[i - k] - prices[i]);
    }
    return dp_0[n - 1];
  }
};

int main(int argc, char *argv[]) { return 0; }
