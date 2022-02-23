#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> res;
  void backtrace(vector<int> &trace, vector<int> &nums, int n, int k) {
    if ((int)trace.size() == k) {
      res.push_back(trace);
      return;
    }
    for (int i = n; i < (int)nums.size(); i++) {
      trace.push_back(nums[i]);
      backtrace(trace, nums, i + 1, k);
      trace.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      nums.push_back(i + 1);
    }
    vector<int> trace;
    backtrace(trace, nums, 0, k);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  int k;
  cin >> k;

  Solution *s = new (Solution);
  s->combine(n, k);
  for (int i = 0; i < (int)s->res.size(); i++) {
    for (int j = 0; j < k; j++) {
      cout << s->res[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
