#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> vis(26), num(26);
    for (char ch : s) {
      num[ch - 'a']++;
    }

    string res;
    for (char c : s) {
      // c is't exist before
      if (vis[c - 'a'] == 0) {
        while (!res.empty() && res.back() > c) {
          if (num[res.back() - 'a'] > 0) {
            vis[res.back() - 'a'] = 0;
            res.pop_back();
          } else {
            break;
          }
        }
        vis[c - 'a'] = 1;
        res.push_back(c);
      }
      num[c - 'a']--;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  string s;
  char tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    s.push_back(tmp);
  }

  Solution *r = new (Solution);
  cout << r->removeDuplicateLetters(s) << "\n";

  return 0;
}
