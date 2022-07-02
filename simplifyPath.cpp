#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> q;
    while (!path.empty()) {
      while (path.front() == '/') {
        path.erase(path.begin(), path.begin() + 1);
      }
      string tmp;
      while (!path.empty() && path.front() != '/') {
        tmp.push_back(path.front());
        path.erase(path.begin(), path.begin() + 1);
      }
      if (tmp == "..") {
        if (!q.empty()) {
          q.pop();
        }
      } else if (tmp == ".") {
      } else if (!tmp.empty()) {
        q.push(tmp);
      }
    }

    if (q.empty()) {
      return "/";
    }
    string res;
    while (!q.empty()) {
      res = "/" + q.top() + res;
      q.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->simplifyPath(s) << endl;
  return 0;
}
