#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  //   bool find = false;
  //   void findSum(vector<int> &nums, vector<int> &res, int n, int target) {
  //     if (res.size() == 2) {
  //       if (nums[res[0] - 1] + nums[res[1] - 1] == target) {
  //         find = true;
  //       }
  //       return;
  //     }
  //     for (int i = n; i < (int)nums.size(); i++) {
  //       if (find) {
  //         return;
  //       }
  //       res.push_back(i + 1);
  //       findSum(nums, res, i + 1, target);
  //       if (find) {
  //         return;
  //       }
  //       res.pop_back();
  //     }
  //   }
  //
  //   vector<int> twoSum(vector<int> &numbers, int target) {
  //     vector<int> res;
  //     findSum(numbers, res, 0, target);
  //     return res;
  //   }

  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res = {-1, -1};
    int left = 0, right = (int)numbers.size() - 1;
    int sum = 0;
    while (left <= right) {
      sum = numbers[left] + numbers[right];
      if (sum == target) {
        res[0] = left + 1;
        res[1] = right + 1;
        break;
      }
      if (sum > target) { // bigger, right move to left
        right--;
      } else if (sum < target) { // smaller, left move to right
        left++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  int tmp;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }
  int target;
  cin >> target;

  Solution *s = new (Solution);
  vector<int> res = s->twoSum(nums, target);
  for (int j = 0; j < 2; j++) {
    cout << res[j] << " ";
  }
  cout << "\n";

  return 0;
}
