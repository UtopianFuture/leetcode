#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int left = 0, right = 0;
    int match = 0;
    vector<int> res;
    unordered_map<char, int> has;
    unordered_map<char, int> need;
    for (int i = 0; i < (int)p.size(); i++) {
      need[p[i]]++;
    }

    char tmp;
    while (right < (int)s.size()) {
      tmp = s[right];
      if (need.count(tmp)) {
        has[tmp]++;
        if (has[tmp] == need[tmp]) {
          match++;
        }
      }
      right++;
      while (match == (int)need.size()) {
        if (right - left == (int)p.size()) {
          res.push_back(left);
        }
        tmp = s[left];
        if (need.count(tmp)) {
          has[tmp]--;
          if (has[tmp] < need[tmp]) {
            match--;
          }
        }
        left++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, t;
  cin >> s;
  cin >> t;
  Solution *c = new (Solution);
  vector<int> res = c->findAnagrams(s, t);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
