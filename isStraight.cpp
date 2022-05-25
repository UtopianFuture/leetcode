#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isStraight(vector<int> &nums) {
    sort(nums.begin(), nums.end(), less<int>());
    int n = nums.size();
    int i = 0;
    int zero_nums = 0;
    while (nums[i] == 0) {
      i++;
      zero_nums++;
    }
    i++;
    for (; i < n; i++) {
      if (nums[i] == nums[i - 1]) {
        return false;
      }
      int tmp = nums[i] - nums[i - 1];
      if (tmp != 1) {
        zero_nums = zero_nums - tmp + 1;
        if (zero_nums < 0) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n = 5;
  vector<int> nums(5, 0);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << (bool)s->isStraight(nums) << "\n";
  return 0;
}
