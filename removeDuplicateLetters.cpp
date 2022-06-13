#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> visited(26), num(26);
    for (auto c : s) {
      num[c - 'a']++;
    }

    string res;
    for (auto c : s) {
      if (visited[c - 'a'] != 1) {
        while (!res.empty() && res.back() > c) {
          if (num[c - 'a'] > 0) {
            visited[res.back() - 'a'] = 0;
            res.pop_back();
          } else {
            break;
          }
        }
        res.push_back(c);
        visited[c - 'a'] = 1;
      }
      num[c - 'a']--;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *r = new Solution;
  cout << r->removeDuplicateLetters(s) << "\n";

  return 0;
}
