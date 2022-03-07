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

  void generate(vector<string> &res, string res_i, string s, int n) {
    if (n == (int)res_i.size()) {
      if (isValid(res_i)) {
        res.push_back(res_i);
      }
      return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
      res_i.push_back(s[i]);
      generate(res, res_i, s, n);
      res_i.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string s = "()";
    generate(res, "", s, n * 2);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new (Solution);
  vector<string> res = s->generateParenthesis(n);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << "\n";
  }

  return 0;
}
