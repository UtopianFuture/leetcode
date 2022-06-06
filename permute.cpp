#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<int> nums;

public:
  void backtrace(vector<vector<int>> &res, int start, int end) {
    if (start == end) {
      res.emplace_back(nums);
      return;
    }

    for (int i = start; i < end; i++) {
      swap(nums[i], nums[start]);
      backtrace(res, start + 1, end);
      swap(nums[i], nums[start]);
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    this->nums = nums;
    vector<vector<int>> res;
    backtrace(res, 0, nums.size());
    return res;
  }
};

int main(int argc, char *argv[]) {
  int n = 0;
  // scanf("%d", &n);
  cin >> n;

  vector<int> nums;
  int sum = 1;
  // scanf("%d", &nums[i]);
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
    sum *= tmp;
  }

  Solution *s = new (Solution);
  vector<vector<int>> res = s->permute(nums);
  for (int i = 0; i < sum; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }

  return 0;
}
