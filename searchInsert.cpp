#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int mid;

    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return target > nums[mid] ? mid + 1 : mid;
  }
};

int main(int argc, char *argv[]) { return 0; }
