#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string decodeString(string s) {
    stack<char> stk;
    string s2 = "";
    string ret = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ']') {
        stk.push(s[i]);
      } else {
        while (stk.top() != '[') {
          s2 += stk.top();
          stk.pop();
        }
        stk.pop();
        int num = 0;
        int n = 0;
        while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
          int po = pow(10, n);
          num += (stk.top() - '0') * po;
          n++;
          stk.pop();
        }
        for (int p = 0; p < num; p++) {
          for (int j = s2.size() - 1; j >= 0; j--)
            stk.push(s2[j]);
        }
        s2 = "";
      }
    }
    while (!stk.empty()) {
      ret += stk.top();
      stk.pop();
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->decodeString(s) << endl;
  return 0;
}
