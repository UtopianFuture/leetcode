#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = (int)nums.size();
    int res = 0;
    vector<vector<long>> dp(n, vector<long>(n, 0));

    for (int i = 0; i < n; i++) {
      dp[i][i] = nums[i];
      if (dp[i][i] >= lower && dp[i][i] <= upper) {
        res++;
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = dp[i][j - 1] + nums[j];
        if (dp[i][j] >= lower && dp[i][j] <= upper) {
          res++;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, lower, upper;
  cin >> n >> lower >> upper;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << s->countRangeSum(nums, lower, upper) << endl;
  return 0;
}
