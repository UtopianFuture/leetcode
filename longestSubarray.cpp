#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
public:
  int absolute(vector<int> nums, int left, int right) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = left; i <= right; i++) {
      min = min < nums[i] ? min : nums[i];
      max = max > nums[i] ? max : nums[i];
    }
    return abs(min - max);
  }

  int longestSubarray(vector<int> &nums, int limit) {
    int min = INT_MAX;
    int max = INT_MIN;
    int res = 0;
    int n = (int)nums.size();
    int left = 0, right = 0;
    int tmp, abs;
    while (right < n) {
      tmp = nums[right];
      abs = absolute(nums, left, right);
      if (abs <= limit) {
        res = res > (right - left + 1) ? res : (right - left + 1);
      }
      while (absolute(nums, left, right) > limit) {
        left++;
      }
      right++;
    }
    return res;
  }
};

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    deque<int> maxq, minq;
    int res = 0;
    int n = (int)nums.size();
    int left = 0, right = 0;
    int tmp;
    while (right < n) {
      tmp = nums[right];
      while (!maxq.empty() && maxq.back() < tmp) {
        maxq.pop_back();
      }
      while (!minq.empty() && minq.back() > tmp) {
        minq.pop_back();
      }

      maxq.push_back(tmp);
      minq.push_back(tmp);

      while (!maxq.empty() && !minq.empty() &&
             maxq.front() - minq.front() > limit) {
        if (maxq.front() == nums[left]) {
          maxq.pop_front();
        }
        if (minq.front() == nums[left]) {
          minq.pop_front();
        }
        left++;
      }
      res = max(res, right - left + 1);
      right++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
