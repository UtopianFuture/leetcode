#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = (int)s.size();
    stack<int> stk;
    // dp[i] record the longest valid parentheses that end with s[i - 1].
    vector<int> dp(n + 1, 0);

    int tmp, len;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
        dp[i + 1] = 0;
      } else {
        if (!stk.empty()) {
          tmp = stk.top();
          stk.pop();
          len = i - tmp + 1 + dp[tmp];
          dp[i + 1] = len;
        } else {
          dp[i + 1] = 0;
        }
      }
    }

    int res = INT_MIN;
    for (int i = 0; i <= n; i++) {
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->longestValidParentheses(s) << endl;
  return 0;
}
