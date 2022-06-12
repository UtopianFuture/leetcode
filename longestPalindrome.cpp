#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string longestPalindrome(string s) {
    int n = (int)s.size();
    if (n < 2) {
      return s;
    }
    if (n == 2) {
      if (s[0] == s[1]) {
        return s;
      } else {
        return s.substr(0, 1);
      }
    }
    int m = 1, start = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
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
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        } else {
          dp[i][j] = 0;
        }
        if (dp[i][j] && l > m) {
          m = l;
          start = i;
        }
      }
    }
    return s.substr(start, m);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->longestPalindrome(s) << endl;
  return 0;
}
