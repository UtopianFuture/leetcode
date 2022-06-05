#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = (int)nums.size();
    if (n < 2) {
      return false;
    }
    sort(nums.begin(), nums.end(), less<int>());

    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }
    if (sum % 2) {
      return false;
    } else {
      sum /= 2;
    }

    // dp[i][j] present if there is a solution that choose some numbers
    // (include 0 number) from nums[0, i] and the sum is equal j.
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++) {
      dp[i][0] = true; // we can choose 0 number and the sum is always 0.
    }
    dp[0][nums[0]] = true; // we can only choose nums[0].

    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j < nums[i]) {
          // nums[i] should not add, because nums[i] is larger than sum(j),
          // so dp[i][j] must be false if nums[i] add.
          dp[i][j] = dp[i - 1][j];
        } else {
          // nums[i] is smaller than sum(j), so if we add nums[i], dp[i][j]
          // equals dp[i -1][j - nums[i]], if we don't add, dp[i][j] equals
          // dp[i- 1][j].
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
        }
      }
    }
    return dp[n - 1][sum];
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
  cout << (bool)s->canPartition(nums) << endl;
  return 0;
}
