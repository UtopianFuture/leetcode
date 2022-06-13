#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int res = -1;
    int left = 0, right = (int)nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        res = mid;
        break;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
