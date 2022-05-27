#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool checkPalindrome(string s, int left, int right) {
    for (int i = left, j = right; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }

    return true;
  }

  bool validPalindrome(string s) {
    int left = 0, right = (int)s.length() - 1;
    while (left <= right) {
      if (s[left] != s[right]) {
        return checkPalindrome(s, left + 1, right) ||
               checkPalindrome(s, left, right - 1);
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
  cout << (bool)so->validPalindrome(s) << "\n";

  return 0;
}
