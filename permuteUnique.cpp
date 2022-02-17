#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isRepeat(vector<int> nums, int start, int end) {
    for (int i = start; i < end; i++) {
      if (nums[i] == nums[end]) {
        return true;
      }
    }

    return false;
  }

  void backtrace(vector<vector<int>> &res, vector<int> &nums, int first,
                 int len) {
    if (first == len) {
      res.emplace_back(nums);
      return;
    }

    for (int i = first; i < len; i++) {
      if (i != first && isRepeat(nums, first, i)) {
        continue;
      }
      swap(nums[i], nums[first]);
      backtrace(res, nums, first + 1, len);
      swap(nums[i], nums[first]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    backtrace(res, nums, 0, (int)nums.size());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n = 0;
  cin >> n;

  vector<int> nums;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  Solution *s = new (Solution);
  vector<vector<int>> res = s->permuteUnique(nums);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    printf("\n");
  }

  return 0;
}
