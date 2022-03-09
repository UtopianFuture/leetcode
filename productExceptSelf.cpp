#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int size = nums.size();
    int left[size], right[size];
    left[0] = 1, right[size - 1] = 1;
    for (int i = 1, j = size - 2; i < size && j >= 0; i++, j--) {
      left[i] = left[i - 1] * nums[i - 1];
      right[j] = right[j + 1] * nums[j + 1];
    }

    vector<int> res;
    for (int i = 0; i < size; i++) {
      res.push_back(left[i] * right[i]);
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

  Solution *s = new (Solution);
  vector<int> res = s->productExceptSelf(nums);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
