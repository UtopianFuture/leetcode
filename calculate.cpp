#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int evalRPN(vector<string> s) {
    int n = (int)s.size();
    stack<long> st;
    string tmp;
    for (int i = 0; i < n; i++) {
      tmp = s[i][0];
      if (!(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")) {
        st.push(stol(s[i]));
      } else {
        long op1 = st.top();
        st.pop();
        long op2 = st.top();
        st.pop();
        switch (tmp[0]) {
        case '+':
          st.push(op1 + op2);
          break;
        case '-':
          st.push(op2 - op1);
          break;
        case '*':
          st.push(op1 * op2);
          break;
        case '/':
          st.push(op2 / op1);
          break;
        }
      }
    }
    return (int)st.top();
  }

  int calculate(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == ' ') {
        s.erase(s.begin() + i, s.begin() + i + 1);
        i--;
      } else if (s[i] == '-' && (i == 0 || s[i - 1] == '(')) {
        if (i == 0) {
          s.insert(s.begin(), '0');
        } else {
          s.insert(s.begin() + i, '0');
        }
      }
    }

    unordered_map<char, int> prio;
    prio[')'] = 0;
    prio['/'] = 1;
    prio['*'] = 1;
    prio['+'] = 2;
    prio['-'] = 2;
    prio['('] = 3;
    prio['#'] = 4;
    stack<char> s1;
    stack<string> s2;
    s1.push('#');
    s += '#';
    char c;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
      c = s[i];
      if (c == ' ') {
        continue;
      }
      if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (prio[c] < prio[s1.top()]) {
          s1.push(c);
        } else {
          while (prio[c] >= prio[s1.top()]) {
            string tmp;
            tmp.push_back(s1.top());
            s2.push(tmp);
            s1.pop();
          }
          s1.push(c);
        }
      } else if (c == '(') {
        s1.push(c);
      } else if (c == ')') {
        while (s1.top() != '(') {
          string tmp;
          tmp.push_back(s1.top());
          s2.push(tmp);
          s1.pop();
        }
        s1.pop();
      } else if (c == '#') {
        while (s1.top() != '#') {
          string tmp;
          tmp.push_back(s1.top());
          s2.push(tmp);
          s1.pop();
        }
      } else {
        long digit = 1;
        long tmp = 0;
        string tmps;
        while (s[i] >= '0' && s[i] <= '9') {
          tmps.insert(tmps.begin(), s[i]);
          i++;
        }
        i--;
        while (!tmps.empty()) {
          tmp += (tmps.front() - '0') * digit;
          digit *= 10;
          tmps.erase(tmps.begin(), tmps.begin() + 1);
        }
        s2.push(to_string(tmp));
      }
    }

    vector<string> tmps;
    while (!s2.empty()) {
      tmps.insert(tmps.begin(), s2.top());
      s2.pop();
    }

    return evalRPN(tmps);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->calculate(s) << "\n";
  return 0;
}
