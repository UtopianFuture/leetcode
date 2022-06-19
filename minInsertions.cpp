#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minInsertions(string s) {
    int res = 0, need = 0;
    for (char c : s) {
      if (c == '(') {
        need += 2;
        if (need % 2) {
          need--;
          res++;
        }
      } else {
        need--;
        if (need == -1) {
          need = 1;
          res++;
        }
      }
    }
    return res + need;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->minInsertions(s) << endl;
  return 0;
}
