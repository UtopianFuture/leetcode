#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/gureshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
private:
  vector<vector<int>> res;

public:
  void backtrace(vector<int> nums, vector<int> tmp, int first, int len) {
    if ((int)tmp.size() == 3) {
      if (tmp[0] + tmp[1] + tmp[2] == 0) {
        res.push_back(tmp);
      }
      return;
    }

    for (int i = first; i < len; i++) {
      tmp.push_back(nums[i]);
      backtrace(nums, tmp, i + 1, len);
      tmp.pop_back();
    }
  }

  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = (int)nums.size();
    if (n < 3) {
      return res;
    }
    vector<int> tmp;
    backtrace(nums, tmp, 0, n);
    int s = (int)res.size();
    if (s == 1) {
      return res;
    }
    for (int i = 0; i < s; i++) {
      sort(res[i].begin(), res[i].end(), less<int>());
    }
    sort(res.begin(), res.end(), less<vector<int>>());
    for (int i = 0; i < (int)res.size() - 1; i++) {
      if (res[i] == res[i + 1]) {
        res.erase(res.begin() + i, res.begin() + i + 1);
        i--;
      }
    }
    return res;
  }
};

class Solution2 {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int n = (int)nums.size();
    if (n < 3)
      return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0)
        return res;
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          res.push_back({nums[left], nums[right], nums[i]});
          while (right > left && nums[right] == nums[right - 1])
            right--;
          while (right > left && nums[left] == nums[left + 1])
            left++;
          left++;
          right--;
        }
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

  Solution1 *s = new Solution1;
  vector<vector<int>> res = s->threeSum(nums);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
