#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    if (m == 0 && n != 0) {
      return false;
    }

    int poss = 0;
    int i = 0;
    for (i = 0; i < m; i++) {
      if (i == m - 1 || (i + 1 < m && p[i + 1] != '*')) {
        if (p[i] == s[poss] || p[i] == '.') {
          poss++;
        } else {
          return false;
        }
        if (poss == n) {
          break;
        }
      } else if (p[i + 1] == '*') {
        string tmpp = p;
        tmpp.erase(tmpp.begin(), tmpp.begin() + i + 2);
        string tmps = s.substr(poss, n - poss);
        for (int j = 0; j <= n - poss; j++) {
          if (j == 0) {
            // erase s[i] and s[i +1]
          } else {
            // erase s[i + 1] = '*'
            tmpp.insert(tmpp.begin(), p[i]);
          }
          if (isMatch(tmps, tmpp)) {
            return true;
          }
        }
      }
    }
    if (poss == n) {
      if (i == m - 1 || (i + 2 == m - 1 && p[i + 2] == '*'))
        return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, p;
  cin >> s >> p;

  Solution *so = new Solution;
  cout << so->isMatch(s, p) << endl;
  return 0;
}
