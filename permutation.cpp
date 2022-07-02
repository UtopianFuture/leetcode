#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<string> res;

public:
  void backtrace(string s, int start, int end) {
    if (start == end) {
      this->res.push_back(s);
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (s[i] == s[start]) {
        continue;
      }
      swap(s[i], s[start]);
      backtrace(s, start + 1, end);
      swap(s[i], s[start]);
    }
  }

  vector<string> permutation(string s) {
    sort(s.begin(), s.end(), less<char>());

    string tmp;
    backtrace(s, 0, s.size());
    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  vector<string> res = so->permutation(s);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}
