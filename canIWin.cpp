#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  // int used = 0;
  int desiredTotal;
  unordered_map<int, bool> dp;
  int maxChoosableInteger;

public:
  bool dfs(int used, int total) {
    if (dp[used] == 0) {
      for (int i = 1; i <= maxChoosableInteger; i++) {
        if (used & (1 << i)) {
          continue;
        }
        if (total + i >= desiredTotal) {
          dp[used] = 1;
          return true;
        }
        // used |= (1 << i);
        // desiredTotal -= i;
        // if another one return true, it means this one is lose.
        if (!dfs(used | (1 << i), total + i)) {
          dp[used] = 1;
          return true;
        }
        // desiredTotal += i;
        // used &= (0 << i);
      }
      dp[used] = false;
    }
    return dp[used];
  }

  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
      return false;
    }

    this->desiredTotal = desiredTotal;
    this->maxChoosableInteger = maxChoosableInteger;
    return dfs(0, 0);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int maxChoosableInteger, desiredTotal;
  cin >> maxChoosableInteger >> desiredTotal;

  Solution *s = new Solution;
  cout << (bool)s->canIWin(maxChoosableInteger, desiredTotal) << endl;
  return 0;
}
