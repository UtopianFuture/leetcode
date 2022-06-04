#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = (int)nums.size();
    vector<bool> dp(n, 0);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
      if (i == n - 1 && dp[i]) {
        return true;
      }
      if (dp[i]) {
        for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
          dp[j] = true;
        }
        if (dp[n - 1]) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << s->canJump(nums) << endl;
  return 0;
}
