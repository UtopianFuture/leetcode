#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();
    if (n < 3) {
      return 0;
    }
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = 3; l <= n; l++) {
      for (int i = 0; i <= n - l; i++) {
        int j = i + l - 1;
        if (j >= n) {
          continue;
        }
        if (l == 3) {
          if (nums[i + 1] - nums[i] == nums[j] - nums[j - 1]) {
            dp[i][j] = 1;
            res++;
          } else {
            dp[i][j] = 0;
          }
        } else {
          if (dp[i][j - 1] == 1 &&
              nums[j] - nums[j - 1] == nums[i + 1] - nums[i]) {
            dp[i][j] = dp[i][j - 1];
            res++;
          } else {
            dp[i][j] = 0;
          }
        }
      }
    }
    return res;
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
  cout << s->numberOfArithmeticSlices(nums) << endl;
  return 0;
}
