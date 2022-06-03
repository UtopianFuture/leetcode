#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numDecodings(string s) {
    int n = (int)s.size();
    if (s[0] == '0') {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    vector<int> dp(n, 0);
    dp[0] = 1;
    if (s[1] == '0' && stoi(s.substr(0, 2)) > 26) {
      return 0;
    }
    if (stoi(s.substr(0, 2)) > 26) {
      dp[1] = 1;
    } else if (s[1] == '0') {
      dp[1] = 1;
    } else {
      dp[1] = 2;
    }

    for (int i = 2; i < n; i++) {
      if (s[i] == '0') {
        if (s[i - 1] == '0') {
          return 0;
        }
        if (stoi(s.substr(i - 1, 2)) > 26) {
          return 0;
        }
        dp[i - 1] = dp[i - 2];
        dp[i] = dp[i - 1];
      } else if (stoi(s.substr(i - 1, 2)) > 26 || s[i - 1] == '0') {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
    }
    return dp[n - 1];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->numDecodings(s) << "\n";
  return 0;
}
