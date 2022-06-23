#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool check(int location, vector<int> dp) {
    for (int i = location + 1; i < (int)dp.size(); i++) {
      dp[i] += dp[i - 1];
      if (dp[i] < 0) {
        return false;
      }
    }

    for (int i = 0; i <= location; i++) {
      if (i == 0) {
        dp[i] += dp[dp.size() - 1];
      } else {
        dp[i] += dp[i - 1];
      }
      if (dp[i] < 0) {
        return false;
      }
    }
    return true;
  }

  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    vector<int> dp(n, 0);
    int location;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      dp[i] = gas[i] - cost[i];
      if (dp[i] >= 0 && flag) {
        location = i;
        flag = false;
      }
    }

    for (int i = location; i < n; i++) {
      if (dp[i] >= 0 && check(i, dp)) {
        return i;
      }
    }
    return -1;
  }
};

class Solution1 {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0, start = 0;
    int min = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++) {
      sum += gas[i] - cost[i];
      if (sum < min) {
        min = sum;
        start = i + 1;
      }
    }
    if (sum < 0) {
      return -1;
    }
    return start == n ? 0 : start;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> gas(n);
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> gas[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }

  Solution *s = new Solution;
  cout << s->canCompleteCircuit(gas, cost) << endl;
  return 0;
}
