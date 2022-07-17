#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int res;

public:
  void backtrace(vector<int> nums, int start, int n, int sum, int target) {
    if (sum >= target) {
      if (sum == target) {
        this->res++;
      }
      return;
    }
    if (start == n) {
      return;
    }

    for (int i = start; i < n; i++) {
      sum += nums[i];
      backtrace(nums, 0, n, sum, target);
      sum -= nums[i];
    }
  }

  int combinationSum4(vector<int> &nums, int target) {
    this->res = 0;
    sort(nums.begin(), nums.end(), less<int>());
    backtrace(nums, 0, nums.size(), 0, target);
    return this->res;
  }
};

class Solution1 {
public:
  int combinationSum4(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), less<int>());
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= target; j++) {
        if (j < nums[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - nums[i - 1]] + dp[i - 1][j];
        }
      }
    }
    return dp[n][target];
  }
};

class Solution2 {
public:
  int combinationSum4(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), less<int>());
    vector<long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < nums[0]; i++) {
      if (target >= nums[0]) {
        dp[i] = 0;
      } else {
        return 0;
      }
    }
    if (target >= nums[0]) {
      dp[nums[0]] = 1;
    } else {
      return 0;
    }

    for (int i = nums[0] + 1; i <= target; i++) {
      for (int j = 0; j < n; j++) {
        if (i < nums[j]) {
          break;
        } else {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    return dp[target];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution2 *s = new Solution2;
  cout << s->combinationSum4(nums, target) << endl;
  return 0;
}
