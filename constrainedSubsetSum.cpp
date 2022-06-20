#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/gureshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    int n = nums.size(), res = nums[0];
    deque<int> dq{0};
    for (int i = 1; i < n; i++) {
      dq.push_back(i);
      while (!dq.empty() && i - dq.front() > k)
        dq.pop_front();
      res = max(res, nums[i] += max(0, nums[dq.front()]));
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n = 5, k = 2;
  // cin >> n >> k;
  vector<int> nums(n);
  // for (int i = 0; i < n; i++) {
  // cin >> nums[i];
  // }

  nums = vector<int>{10, -2, -10, -5, 20};
  Solution *s = new Solution;
  cout << s->constrainedSubsetSum(nums, k) << endl;
  return 0;
}
