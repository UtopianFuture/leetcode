#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, int> map;
    int m = s.size();
    int n = wordDict.size();
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
      map[wordDict[i]] = 1;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && map[s.substr(j, i - j)]) {
          dp[i] = 1;
          break;
        }
      }
    }
    return dp[m];
  }
};

int main(int argc, char *argv[]) { return 0; }
