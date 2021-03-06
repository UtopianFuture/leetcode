#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int n = (int)nums.size();
    if (n < 4) {
      return res;
    }
    sort(nums.begin(), nums.end(), less<int>());
    int left, right;
    int sum;

    for (int i = 0; i < n - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
        break;
      }
      if ((long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
        continue;
      }
      for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
          break;
        }
        if ((long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
          continue;
        }
        left = j + 1;
        right = n - 1;
        while (left < right) {
          sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target) {
            right--;
          } else if (sum < target) {
            left++;
          } else {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[right - 1] == nums[right]) {
              right--;
            }
            right--;
            while (left < right && nums[left + 1] == nums[left]) {
              left++;
            }
            left++;
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
