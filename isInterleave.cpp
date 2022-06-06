#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> dp;

public:
  int check(string s1, int l1, string s2, int l2, string s3) {
    if (l1 + l2 == (int)s3.size()) {
      return 1;
    }

    if (dp[l1][l2] != -1) {
      return dp[l1][l2];
    }

    int res = 0;
    if (l1 < (int)s1.size() && s1[l1] == s3[l1 + l2]) {
      res = check(s1, l1 + 1, s2, l2, s3);
    }
    if (l2 < (int)s2.size() && s2[l2] == s3[l1 + l2]) {
      res = res || check(s1, l1, s2, l2 + 1, s3);
    }

    dp[l1][l2] = res;
    return res;
  }

  bool isInterleave(string s1, string s2, string s3) {
    int l1 = (int)s1.size();
    int l2 = (int)s2.size();
    if (l1 + l2 != (int)s3.size()) {
      return false;
    }
    dp.resize(l1 + 1, vector<int>(l2 + 1, -1));

    return (bool)check(s1, 0, s2, 0, s3);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  Solution *s = new Solution;
  cout << (bool)s->isInterleave(s1, s2, s3);

  return 0;
}
