#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int translateNum(int num) {
    string s = to_string(num);
    int size = (int)s.length();
    if (size == 1) {
      return 1;
    }
    vector<int> dp(size);
    dp[0] = 1;
    int s2 = stoi(s.substr(0, 2));
    if (s2 > 25) {
      dp[1] = 1;
    } else {
      dp[1] = 2;
    }
    if (size == 2) {
      return dp[1];
    }
    for (int i = 2; i < size; i++) {
      s2 = stoi(s.substr(i - 1, 2));
      if (s2 > 25 || stoi(s.substr(i - 1, 1)) == 0) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
    }
    return dp[size - 1];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  cout << s->translateNum(n) << "\n";
  return 0;
}
