#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(string a, string b) {
    if (a.size() == b.size()) {
      return a < b;
    } else {
      return a.size() > b.size();
    }
  }

  string findLongestWord(string s, vector<string> &dictionary) {
    sort(dictionary.begin(), dictionary.end(), cmp);

    int n = s.size();
    for (auto word : dictionary) {
      int m = word.size();
      if (m > n) {
        continue;
      }
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
      }
      for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
      }

      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (word[i - 1] == s[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
          }
        }
      }
      if (dp[m][n] < n && dp[m][n] < n - m) {
        return word;
      }
    }
    return "";
  }
};

int main(int argc, char *argv[]) { return 0; }
