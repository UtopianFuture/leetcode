#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  void backtrace(vector<vector<int>> &res, vector<int> &nums, int first,
                 int len) {
    if (first == len) {
      res.emplace_back(nums);
      return;
    }

    int tmp;
    for (int i = first; i < len; i++) {
      swap(nums[i], nums[first]);
      tmp = i;
      while (tmp > first + 1) {
        swap(nums[tmp], nums[tmp - 1]);
        tmp--;
      }
      backtrace(res, nums, first + 1, len);
      tmp = i;
      while (tmp > first + 1) {
        swap(nums[tmp], nums[tmp - 1]);
        tmp--;
      }
      swap(nums[i], nums[first]);
    }
  }

  vector<vector<int>> getPermutation(vector<int> &nums) {
    vector<vector<int>> res;
    backtrace(res, nums, 0, nums.size());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
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
  vector<vector<int>> res = s->getPermutation(nums);
  for (int i = 0; i < sum; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }

  return 0;
}
