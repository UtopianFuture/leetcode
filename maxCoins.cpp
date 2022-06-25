#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  // unordered_map<vector<int>, int> map;

public:
  int dfs(vector<int> nums) {
    // if (!map[nums]) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    int res = 0, tmp;
    vector<int> tmpnums;
    for (int i = 0; i < n; i++) {
      if (i - 1 == -1) {
        tmp = nums[i] * nums[i + 1];
      } else if (i + 1 == n) {
        tmp = nums[i - 1] * nums[i];
      } else {
        tmp = nums[i - 1] * nums[i] * nums[i + 1];
      }

      tmpnums.assign(nums.begin(), nums.end());
      tmpnums.erase(tmpnums.begin() + i);
      res = max(res, dfs(tmpnums) + tmp);
    }
    return res;
    // map[nums] = res;
    // }
    // return map[nums];
  }

  int maxCoins(vector<int> &nums) { return dfs(nums); }
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
  cout << s->maxCoins(nums) << endl;
  return 0;
}
