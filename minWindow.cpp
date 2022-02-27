#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string minWindow(string s, string t) {
    int left = 0, right = 0;
    int min = 0x7fffffff;
    int start;
    unordered_map<char, int> has;
    unordered_map<char, int> need;
    for (int i = 0; i < (int)t.size(); i++) {
      need[t[i]]++;
    }

    int match = 0; // record how many char has matched
    char tmp;
    while (right < (int)s.size()) {
      tmp = s[right];
      if (need.count(tmp)) {
        // this char is in t, and times matched
        has[tmp]++;
        if ((int)has[tmp] == (int)need[tmp]) {
          match++;
        }
      }
      right++;

      while (match == (int)need.size()) {
        if (right - left < min) {
          min = right - left;
          start = left;
        }
        tmp = s[left];
        if (need.count(tmp)) {
          has[tmp]--;
          if ((int)has[tmp] < (int)need[tmp]) {
            match--;
          }
        }
        left++;
      }
    }

    return min == 0x7fffffff ? "" : s.substr(start, min);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, t;
  cin >> s;
  cin >> t;
  Solution *c = new (Solution);
  string res = c->minWindow(s, t);
  cout << res << "\n";
  return 0;
}
