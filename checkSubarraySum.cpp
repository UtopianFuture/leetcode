#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int checkSubarraySum(vector<int> &nums, int k) {
    int size = (int)nums.size();
    if (size < 2) {
      return false;
    }
    int sum_i = 0, reminder = 0;
    // count the times of this sum
    unordered_map<int, int> times;
    // sum = 0 must be initiated to 1
    times[0] = -1;
    for (int i = 0; i < size; i++) {
      sum_i += nums[i];
      // k = sum_j - sum_i
      reminder = sum_i % k;
      // if sum_j has existed
      if (times.count(reminder)) {
        if (i - times[reminder] >= 2)
          return true;
      } else {
        times[reminder] = i;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, k;
  vector<int> nums;
  int tmp1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp1;
    nums.push_back(tmp1);
  }
  cin >> k;

  Solution *s = new (Solution);
  int res = s->checkSubarraySum(nums, k);
  cout << res << "\n";

  return 0;
}
