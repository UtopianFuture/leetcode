#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
  vector<string> res;

public:
  void dfs(string s, int n, string tmp) {
    if (n == 0 || 0 == (int)s.size()) {
      if (n == 0 && 0 == (int)s.size()) {
        this->res.push_back(tmp.substr(0, (int)tmp.size() - 1));
      }
      return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
      string s1 = s.substr(0, i + 1);
      if ((int)s1.size() > 3) {
        return;
      }
      if ((int)s1.size() == 3 && s1 > "255") {
        return;
      }
      if ((int)s1.size() > 1 && s[0] == '0') {
        return;
      }
      tmp += s1;
      tmp += '.';
      dfs(s.substr((int)s1.size(), (int)s.size() - (int)s1.size()), n - 1, tmp);
      tmp.erase((int)tmp.size() - (int)s1.size() - 1, (int)s1.size() + 1);
    }
  }

  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    if (n < 4 || n > 12) {
      return vector<string>{};
    }

    string tmp;
    dfs(s, 4, tmp);
    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  vector<string> res = so->restoreIpAddresses(s);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
