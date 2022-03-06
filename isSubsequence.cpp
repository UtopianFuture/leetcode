#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int ls = (int)s.size();
    int lt = (int)t.size();

    if (ls == 0) {
      return true;
    }
    for (int i = 0, j = 0; i < lt; i++) {
      if (t[i] == s[j]) {
        j++;
        if (j == ls) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, t;
  cin >> s;
  cin >> t;
  Solution *solu = new (Solution);
  if (solu->isSubsequence(s, t)) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
  return 0;
}
