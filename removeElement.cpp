#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = (int)nums.size();
    int left = 0, right = 0;
    while (right < n) {
      if (nums[right] != val) {
        nums[left] = nums[right];
        left++;
      }
      right++;
    }
    return left;
  }
};

int main(int argc, char *argv[]) { return 0; }
