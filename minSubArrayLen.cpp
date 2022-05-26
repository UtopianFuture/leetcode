#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, right = 0;
    int sum = 0;
    int res = INT_MAX;
    int n = (int)nums.size();
    while (right < n) {
      sum += nums[right];
      if (sum >= target) {
        while (left <= right && sum >= target) {
          res = res < right - left + 1 ? res : right - left + 1;
          sum -= nums[left];
          left++;
        }
      }
      right++;
    }
    if (res == INT_MAX) {
      return 0;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int target;
  cin >> target;
  Solution *s = new Solution;
  cout << s->minSubArrayLen(target, nums);
  return 0;
}
