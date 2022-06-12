#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int n = (int)nums.size();
    int dp = nums[0];
    int _max = dp, _min = 0;
    int sum = nums[0];
    for (int i = 1; i < n; i++) {
      sum += nums[i];
      dp = nums[i] + max(dp, 0);
      _max = max(dp, _max);
    }

    dp = nums[0];
    for (int i = 1; i < n - 1; i++) {
      dp = nums[i] + min(0, dp);
      _min = min(dp, _min);
    }
    return max(sum - _min, _max);
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
  cout << s->maxSubarraySumCircular(nums) << endl;
  return 0;
}
