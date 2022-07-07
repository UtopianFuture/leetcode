#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    nums.insert(nums.begin(), INT_MIN);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        nums.erase(nums.begin() + i, nums.begin() + i + 1);
        i--;
      }
    }

    int res = 1, tmp = 1;
    for (int i = 1; i <= nums.size(); i++) {

      while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
        tmp++;
        i++;
      }
      res = max(res, tmp);
      tmp = 1;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << s->longestConsecutive(nums) << endl;
  return 0;
}
