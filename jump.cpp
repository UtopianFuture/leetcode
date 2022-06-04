#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = (int)nums.size();
    int res = 0;
    int end = 0, fast = 0;
    for (int i = 0; i < n - 1; i++) {
      fast = max(fast, nums[i] + i);
      if (end == i) {
        res++;
        end = fast;
      }
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
  cout << s->jump(nums) << endl;

  return 0;
}
