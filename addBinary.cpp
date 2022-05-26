#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string addBinary(string a, string b) {
    int na = a.length();
    int nb = b.length();
    if (na > nb) {
      b.insert(b.begin(), na - nb, '0');
    } else {
      a.insert(a.begin(), nb - na, '0');
      na = a.length();
    }

    string res;
    char carry = '0';
    while (--na >= 0) {
      if (a[na] == '0' && b[na] == '0' && carry == '0') {
        res.insert(res.begin(), '0');
        carry = '0';
      } else if ((a[na] == '0' && b[na] == '0' && carry == '1') ||
                 (a[na] == '0' && b[na] == '1' && carry == '0') ||
                 (a[na] == '1' && b[na] == '0' && carry == '0')) {
        res.insert(res.begin(), '1');
        carry = '0';
      } else if ((a[na] == '0' && b[na] == '1' && carry == '1') ||
                 (a[na] == '1' && b[na] == '0' && carry == '1') ||
                 (a[na] == '1' && b[na] == '1' && carry == '0')) {
        res.insert(res.begin(), '0');
        carry = '1';
      } else if ((a[na] == '1' && b[na] == '1' && carry == '1')) {
        res.insert(res.begin(), '1');
        carry = '1';
      }
    }
    if (carry == '1') {
      res.insert(res.begin(), carry);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string a, b;
  cin >> a >> b;

  Solution *s = new Solution;
  cout << s->addBinary(a, b) << "\n";
  return 0;
}
