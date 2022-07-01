#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int myAtoi(string s) {
    string tmp;
    long digit = 1;
    long res = 0;
    bool flag = true;
    bool hasflag = false;
    bool hasdigit = false;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == ' ') {
        s.erase(s.begin(), s.begin() + 1);
        i--;
      } else {
        break;
      }
    }

    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (!hasdigit && !hasflag && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '+') {
          flag = true;
        } else {
          flag = false;
        }
        hasflag = true;
        continue;
      }
      if (s[i] >= '0' && s[i] <= '9') {
        tmp.push_back(s[i]);
        hasdigit = true;
      } else {
        break;
      }
    }

    for (int i = 0; i < (int)tmp.size(); i++) {
      if (tmp[i] == '0') {
        tmp.erase(tmp.begin(), tmp.begin() + 1);
        i--;
      } else {
        break;
      }
    }
    if (tmp.size() > 10) {
      if (!flag) {
        return INT_MIN;
      } else {
        return INT_MAX;
      }
    }
    for (int i = (int)tmp.size() - 1; i >= 0; i--) {
      res += (tmp[i] - '0') * digit;
      digit *= 10;
      if (res > INT_MAX) {
        break;
      }
    }
    if (!flag) {
      res = -res;
    }
    if (res > INT_MAX) {
      res = INT_MAX;
    } else if (res < INT_MIN) {
      res = INT_MIN;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  getline(cin, s);

  Solution *so = new Solution;
  cout << so->myAtoi(s) << endl;
  return 0;
}
