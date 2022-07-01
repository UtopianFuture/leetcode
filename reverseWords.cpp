#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string reverseWords(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == ' ') {
        s.erase(s.begin(), s.begin() + 1);
        i--;
      } else {
        break;
      }
    }
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      if (s[i] == ' ') {
        s.erase(s.end() - 1, s.end());
      } else {
        break;
      }
    }

    string res;
    int count = 0;
    string tmp;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      while (i >= 0 && s[i] != ' ') {
        i--;
        count++;
      }
      tmp = s.substr(i + 1, count);
      count = 0;
      res += tmp;
      res.push_back(' ');
      while (i >= 0 && s[i] == ' ') {
        i--;
      }
      i++;
    }
    res.erase(res.end() - 1, res.end());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  getline(cin, s);

  Solution *so = new Solution;
  cout << so->reverseWords(s) << endl;
  return 0;
}
