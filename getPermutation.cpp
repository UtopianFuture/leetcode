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
      tmp = first + 1;
      while (tmp < i) {
        swap(nums[tmp], nums[tmp + 1]);
        tmp++;
      }
      swap(nums[i], nums[first]);
    }
  }

  string getPermutation(int n, int k) {
    vector<vector<int>> res;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      nums.push_back(i + 1);
    }
    backtrace(res, nums, 0, nums.size());
    string s;
    for (int i = 0; i < n; i++) {
      s += to_string(res[k - 1][i]);
    }
    return s;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n = 0, k = 0;
  // scanf("%d", &n);
  cin >> n;
  cin >> k;

  Solution *s = new (Solution);
  string res = s->getPermutation(n, k);
  cout << res << "\n";

  return 0;
}
