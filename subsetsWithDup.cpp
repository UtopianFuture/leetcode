#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> res;
  void backtrace(vector<int> &trace, vector<int> &nums, int n) {
    res.push_back(trace);
    for (int i = n; i < (int)nums.size(); i++) {
      // judge is two elements is repeat,
      // why need `i > n`, see 52 in README.md
      if (!(i > 0 && nums[i] == nums[i - 1] && i > n)) {
        trace.push_back(nums[i]);
      } else {
        continue;
      }
      backtrace(trace, nums, i + 1);
      if (!(i > 0 && nums[i] == nums[i - 1] && i > n)) {
        trace.pop_back();
      }
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> trace;
    // sort, make 44414 to 14444
    // so we can use nums[i] = nums[i - 1] to judeg if two element is repeat
    sort(nums.begin(), nums.end(), less<int>());
    backtrace(trace, nums, 0);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  Solution *s = new (Solution);
  s->subsetsWithDup(nums);
  for (int i = 0; i < (int)s->res.size(); i++) {
    for (int j = 0; j < (int)s->res[i].size(); j++) {
      cout << s->res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
