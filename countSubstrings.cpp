#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int countSubstrings(string s) {
    int n = (int)s.size();
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int right = 0; right < n; right++) {
      for (int left = 0; left <= right; left++) {
        if (s[left] == s[right] &&
            ((right - left < 2) || dp[left + 1][right - 1])) {
          dp[left][right] = 1;
          res++;
        }
      }
    }
    return res;
  }
};

class Solution1 {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      res++;
    }

    for (int l = 2; l <= n; l++) {
      for (int i = 0; i < n; i++) {
        int j = i + l - 1;
        if (j >= n) {
          break;
        }

        if (s[i] == s[j]) {
          if (j - i < 3) {
            dp[i][j] = 1;
            res++;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
            if (dp[i][j]) {
              res++;
            }
          }
        } else {
          dp[i][i] = 0;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s = "aaa";

  Solution1 *so = new Solution1;
  cout << (bool)so->countSubstrings(s) << "\n";

  return 0;
}
