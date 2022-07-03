#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/gureshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string removeKdigits(string num, int k) {
    vector<char> stk;
    for (auto &digit : num) {
      while (!stk.empty() && stk.back() > digit && k) {
        stk.pop_back();
        k--;
      }
      stk.push_back(digit);
    }

    for (; k > 0; --k) {
      stk.pop_back();
    }

    string res = "";
    bool isLeadingZero = true;
    for (auto &digit : stk) {
      if (isLeadingZero && digit == '0') {
        continue;
      }
      isLeadingZero = false;
      res += digit;
    }
    return res == "" ? "0" : res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->removeKdigits(s, n) << endl;
  return 0;
}
