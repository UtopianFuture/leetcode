#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    int n = (int)nums.size();
    int res = 0;
    unordered_map<int, int> m;
    int count = 0;
    m[count] = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i]) {
        count++;
      } else {
        count--;
      }
      if (m.count(count)) {
        res = max(res, i - m[count]);
      } else {
        // if m.count(count) != 0,
        // m[count] is smallest, so we don't need update it.
        m[count] = i;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << s->findMaxLength(nums);

  return 0;
}
