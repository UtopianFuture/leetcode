#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int match = 0;
    int left = 0, right = 0;
    unordered_map<char, int> has;
    unordered_map<char, int> need;
    for (int i = 0; i < (int)s1.size(); i++) {
      need[s1[i]]++;
    }

    char tmp;
    while (right < (int)s2.size()) {
      tmp = s2[right];
      if (need.count(tmp)) {
        has[tmp]++;
        if (need[tmp] == has[tmp]) {
          match++;
        }
      }
      right++;
      while (match == (int)need.size()) {
        if (right - left == (int)s1.size()) {
          return true;
        }
        tmp = s2[left];
        if (need.count(tmp)) {
          has[tmp]--;
          if (has[tmp] < need[tmp]) {
            match--;
          }
        }
        left++;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, t;
  cin >> s;
  cin >> t;
  Solution *c = new (Solution);
  bool res = c->checkInclusion(s, t);
  if (res) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }

  return 0;
}
