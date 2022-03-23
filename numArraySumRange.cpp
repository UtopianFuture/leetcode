#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class NumArray {
  vector<int> sum;

public:
  NumArray(vector<int> &nums) {
    sum.resize(nums.size() + 1);
    for (int i = 0; i < (int)nums.size(); i++) {
      sum[i + 1] = nums[i] + sum[i];
    }
  }

  int sumRange(int left, int right) { return sum[right + 1] - sum[left]; }
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

  int left, right;
  cin >> left >> right;
  NumArray *obj = new NumArray(nums);
  cout << obj->sumRange(left, right) << "\n";
  return 0;
}
