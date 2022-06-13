#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end(), greater<int>());

    return nums[k - 1];
    for (int i = 0; i < n; i++) {
      // while (i < n - 1 && nums[i] == nums[i + 1]) {
      // i++;
      // }
      k--;
      if (k == 0) {
        return nums[i];
      }
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, k;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cin >> k;

  Solution *s = new Solution;
  cout << s->findKthLargest(nums, k) << endl;
  return 0;
}
