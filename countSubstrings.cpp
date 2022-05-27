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

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s = "abc";

  Solution *so = new Solution;
  cout << (bool)so->countSubstrings(s) << "\n";

  return 0;
}
