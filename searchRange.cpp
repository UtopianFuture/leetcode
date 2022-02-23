#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int upper(vector<int> &nums, int location) {
    int i = location - 1;
    for (i = location - 1; i >= 0; i--) {
      if (nums[i] != nums[location]) {
        break;
      }
    }
    return i + 1;
  }

  int lower(vector<int> &nums, int location) {
    int i = location + 1;
    for (i = location + 1; i < (int)nums.size(); i++) {
      if (nums[i] != nums[location]) {
        break;
      }
    }
    return i - 1;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res = {-1, -1};
    int size = (int)nums.size();
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target) {
        res[0] = upper(nums, mid);
        res[1] = lower(nums, mid);
        return res;
      } else if (nums[mid] > target) {
        high = mid - 1;
        continue;
      } else if (nums[mid] < target) {
        low = mid + 1;
        continue;
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
