#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int n;
  vector<int> nums;

public:
  Solution(vector<int> &nums) {
    this->n = (int)nums.size();
    this->nums = nums;
  }

  int pick(int target) {
    int count = 0;
    int res = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] == target) {
        count++;
        // 1 / count probability choose this number
        if (rand() % count == 0) {
          res = i;
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
  int tmp;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  int target;
  cin >> target;
  Solution *obj = new Solution(nums);
  int param_1 = obj->pick(target);
  cout << param_1 << " ";

  return 0;
}
