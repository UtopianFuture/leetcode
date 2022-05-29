#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;
    int n = (int)tokens.size();
    for (int i = 0; i < n; i++) {
      if (!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
            tokens[i] == "/")) {
        s.push(stoi(tokens[i]));
      } else {
        int op1 = s.top();
        s.pop();
        int op2 = s.top();
        s.pop();
        switch (tokens[i][0]) {
        case '+':
          s.push((op1 + op2));
          break;
        case '-':
          s.push(op2 - op1);
          break;
        case '*':
          s.push(op1 * op2);
          break;
        case '/':
          s.push(op2 / op1);
          break;
        }
      }
    }
    return s.top();
  }
};

int main(int argc, char *argv[]) { return 0; }
