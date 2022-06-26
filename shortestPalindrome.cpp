#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  string shortestPalindrome(string s) {
    int n = s.size();
    string tmp, substring;
    for (int i = 0; i < n; i++) {
      tmp = s;
      substring = s.substr(n - i, i);
      reverse(substring.begin(), substring.end());
      tmp.insert(0, substring);
      if (isPalindrome(tmp)) {
        return tmp;
      }
    }
    return s;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s;
  cin >> s;

  Solution *so = new Solution;
  cout << so->shortestPalindrome(s) << endl;
  return 0;
}
