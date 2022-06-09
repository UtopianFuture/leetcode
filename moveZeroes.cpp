#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 1) {
      return;
    }

    int left = 0, right = 0;
    while (right < n) {
      if (nums[right]) {
        nums[left] = nums[right];
        left++;
      }
      right++;
    }
    for (int i = left; i < n; i++) {
      nums[i] = 0;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
