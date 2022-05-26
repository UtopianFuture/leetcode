#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int res = 0;
    int product = 1;
    int n = (int)nums.size();
    int left = 0, right = 0;
    while (right < n) {
      product *= nums[right];
      while (left <= right && product >= k) {
        product /= nums[left];
        left++;
      }
      res += right - left + 1;
      right++;
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
  cout << s->numSubarrayProductLessThanK(nums, target);

  return 0;
}
