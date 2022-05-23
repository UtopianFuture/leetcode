#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int size = cost.size();
    vector<int> dp(size + 1, 0);

    // dp[0] = cost[0];
    // dp[1] = cost[1];
    for (int i = 2; i <= size; i++) {
      dp[i] = (dp[i - 1] + cost[i - 1]) < (dp[i - 2] + cost[i - 2])
                  ? (dp[i - 1] + cost[i - 1])
                  : (dp[i - 2] + cost[i - 2]);
    }

    return dp[size];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> cost;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    cost.push_back(tmp);
  }

  Solution *s = new Solution;
  cout << s->minCostClimbingStairs(cost) << "\n";
  return 0;
}
