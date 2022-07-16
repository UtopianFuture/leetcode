#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      if (nums[0] != nums[1]) {
        return 2;
      }
      return 1;
    }

    vector<int> dp(n, 1);
    if (nums[1] - nums[0] > 0) {
      dp[1] = 2;
    } else if (nums[1] - nums[0] < 0) {
      dp[1] = -2;
    }

    for (int i = 2; i < n; i++) {
      for (int j = 0; j < i; j++) {
        int tmp = nums[i] - nums[j];
        if (dp[j] == 1) {
          if (tmp > 0) {
            dp[i] = dp[j] + 1;
          } else if (tmp < 0) {
            dp[i] = -(dp[j] + 1);
          }
        } else {
          if (tmp > 0 && dp[j] < 0) {
            dp[i] = dp[i] > -dp[j] + 1 ? dp[i] : -dp[j] + 1;
          } else if (tmp < 0 && dp[j] > 0) {
            dp[i] = -(dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1);
          } else {
            dp[i] = abs(dp[j]) > abs(dp[i]) ? dp[j] : dp[i];
          }
        }
      }
    }

    return abs(dp[n - 1]);
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
  cout << s->wiggleMaxLength(nums) << endl;
  return 0;
}
