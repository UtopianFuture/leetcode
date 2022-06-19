#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minAddToMakeValid(string s) {
    stack<char> stk;
    for (int i = 0; i < (int)s.size(); i++) {
      if (stk.empty()) {
        stk.push(s[i]);
        continue;
      }
      if (s[i] == '(') {
        stk.push(s[i]);
      } else {
        if (stk.top() == '(') {
          stk.pop();
        } else {
          stk.push(s[i]);
        }
      }
    }
    return (int)stk.size();
  }
};

int main(int argc, char *argv[]) { return 0; }
