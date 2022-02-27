#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    int max = 0;
    unordered_map<char, int> has;

    char tmp;
    while (right < (int)s.size()) {
      tmp = s[right];
      while (has[tmp] != 0) {
        has[s[left]] = 0;
        left++;
      }
      has[tmp]++;
      right++;
      max = max > (right - left) ? max : (right - left);
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;
  Solution *c = new (Solution);
  int res = c->lengthOfLongestSubstring(s);
  cout << res << "\n";

  return 0;
}
