#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int lower_bound(vector<int> nums, int mid) {
    int res = mid - 1;
    while (res >= 0 && nums[res] == nums[mid]) {
      res--;
    }
    return res + 1;
  }

  int upper_bound(vector<int> nums, int mid) {
    int res = mid + 1;
    while (res < (int)nums.size() && nums[res] == nums[mid]) {
      res++;
    }
    return res - 1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res{-1, -1};
    if ((int)nums.size() == 0) {
      return res;
    }
    int left = 0, right = (int)nums.size();
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        res = {lower_bound(nums, mid), upper_bound(nums, mid)};
        break;
      }
    }
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

  int target;
  cin >> target;

  Solution *s = new (Solution);
  vector<int> res = s->searchRange(nums, target);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
