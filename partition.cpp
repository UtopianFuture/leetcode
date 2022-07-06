#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> dp;
  string s;
  vector<vector<string>> res;

public:
  void backtrace(vector<string> tmp, int start, int n) {
    if (start == n) {
      this->res.push_back(tmp);
      return;
    }

    for (int i = start; i < n; i++) {
      if (isPalindrome(start, i) == 1) {
        tmp.push_back(this->s.substr(start, i - start + 1));
        backtrace(tmp, i + 1, n);
        tmp.pop_back();
      }
    }
  }

  int isPalindrome(int i, int j) {
    if (dp[i][j]) {
      return dp[i][j];
    }

    if (i >= j) {
      return 1;
    }

    dp[i][j] = (s[i] == s[j] ? isPalindrome(i + 1, j - 1) : -1);
    return dp[i][j];
  }

  vector<vector<string>> partition(string s) {
    this->s = s;
    int n = s.size();
    dp.resize(n, vector<int>(n, 0));

    vector<string> tmp;
    backtrace(tmp, 0, n);
    return this->res;
  }
};

int main(int argc, char *argv[]) { return 0; }
