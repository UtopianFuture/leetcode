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
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    // for (int i = 0; i <= n; i++) {
    // dp[i][0] = true; // we can choose 0 number and the sum is always 0.
    // }
    // dp[0][nums[0]] = true; // we can only choose nums[0].
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j < nums[i - 1]) {
          // nums[i] should not add, because nums[i] is larger than sum(j),
          // so dp[i][j] must be false if nums[i] add.
          dp[i][j] = dp[i - 1][j];
        } else {
          // nums[i] is smaller than sum(j), so if we add nums[i], dp[i][j]
          // equals dp[i -1][j - nums[i]], if we don't add, dp[i][j] equals
          // dp[i- 1][j].
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
        }
      }
    }
    return dp[n][sum];
  }
};

class Solution1 {
private:
  vector<int> used;

public:
  bool backtrace(vector<int> nums, vector<int> used, int sum, int target) {
    if (sum == target) {
      return true;
    }

    for (int i = 0; i < (int)nums.size(); i++) {
      if (used[i] == 1) {
        continue;
      }

      sum += nums[i];
      if (sum > target) {
        sum -= nums[i];
        continue;
      }
      used[i] = 1;
      if (backtrace(nums, used, sum, target)) {
        return true;
      }
      used[i] = 0;
      sum -= nums[i];
    }
    return false;
  }

  bool canPartition(vector<int> &nums) {
    int sum = 0;
    int n = (int)nums.size();
    used.resize(n, 0);
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }

    if (sum % 2) {
      return false;
    }

    sum /= 2;
    return backtrace(nums, used, 0, sum);
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

  Solution1 *s = new Solution1;
  cout << (bool)s->canPartition(nums) << endl;
  return 0;
}
