#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string up(string str, int location) {
    if (str[location] == '9') {
      str[location] = '0';
    } else {
      str[location] = str[location] + 1;
    }
    return str;
  }

  string down(string str, int location) {
    if (str[location] == '0') {
      str[location] = '9';
    } else {
      str[location] = str[location] - 1;
    }
    return str;
  }

  int openLock(vector<string> &deadends, string target) {
    int res = 0;
    string init = "0000";
    if (target == init) {
      return res;
    }
    unordered_map<string, int> visited;
    unordered_map<string, int> map;
    for (int i = 0; i < (int)deadends.size(); i++) {
      map[deadends[i]] = 1;
    }

    queue<string> q;
    string str;
    q.push(init);
    int n;
    while (!q.empty()) {
      n = (int)q.size();
      for (int i = 0; i < n; i++) {
        str = q.front();
        q.pop();
        if (map[str] == 1) {
          continue;
        }
        if (str == target) {
          return res;
        }

        for (int j = 0; j < 4; j++) {
          string tmp1 = up(str, j);
          if (visited[tmp1] != 1) {
            q.push(tmp1);
            visited[tmp1] = 1;
          }

          string tmp2 = down(str, j);
          if (visited[tmp2] != 1) {
            q.push(tmp2);
            visited[tmp2] = 1;
          }
        }
      }
      res++;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<string> deadends(n);
  for (int i = 0; i < n; i++) {
    cin >> deadends[i];
  }

  string target;
  cin >> target;

  Solution *s = new Solution;
  cout << s->openLock(deadends, target);
  return 0;
}
