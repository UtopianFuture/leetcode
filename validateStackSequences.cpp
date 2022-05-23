#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    int i = 0, j = 0;
    while (i < (int)pushed.size()) {
      s.push(pushed[i++]);
      // pushed.pop_back();
      cout << s.top() << popped.front();
      while (!s.empty() && s.top() == popped[j]) {
        s.pop();
        j++;
      }
    }
    return s.empty() && j == (int)popped.size();
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> pushed, popped;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    pushed.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    popped.push_back(tmp);
  }

  Solution *s = new Solution;
  cout << (bool)s->validateStackSequences(pushed, popped);
  return 0;
}
