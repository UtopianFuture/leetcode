#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < (int)s.length(); i++) {
      if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
        s.erase(s.begin() + i, s.begin() + i + 1);
        i--;
      }
    }
    int left = 0, right = (int)s.length() - 1;
    while (left <= right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s = "0P";

  Solution *so = new Solution;
  cout << (bool)so->isPalindrome(s) << "\n";
  return 0;
}
