#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isValid(string s) {
    stack<char> res;
    int size = (int)s.size();
    if (size == 0) {
      return true;
    }

    for (int i = 0; i < size; i++) {
      if (res.empty()) {
        res.push(s[i]);
        continue;
      }
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        res.push(s[i]);
      } else {
        switch (s[i]) {
        case ')':
          if (res.top() == '(') {
            res.pop();
          } else {
            res.push(s[i]);
          }
          break;
        case ']':
          if (res.top() == '[') {
            res.pop();
          } else {
            res.push(s[i]);
          }
          break;
        case '}':
          if (res.top() == '{') {
            res.pop();
          } else {
            res.push(s[i]);
          }
          break;
        }
      }
    }

    return res.empty();
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *res = new (Solution);
  if (res->isValid(s)) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
  return 0;
}
