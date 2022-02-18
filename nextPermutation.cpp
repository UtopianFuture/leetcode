#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int i = nums.size() - 1;
    int small = 0, big = 0;
    while (i > 0) {
      // find the first ascending order
      if (nums[i - 1] < nums[i]) {
        small = i - 1;
        break;
      }
      i--;
    }
    // nums already descending order,
    // reverse it directly
    if (i == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    i = nums.size() - 1;
    int max = 0x7fffffff;
    while (i > small) {
      // find the smallest number that bigger than nums[small]
      if (nums[i] > nums[small]) {
        if (nums[i] < max) {
          max = nums[i];
          big = i;
        }
      }
      i--;
    }
    // swap small and big
    swap(nums[small], nums[big]);
    // the number after small should be ascending order
    reverse(nums.begin() + small + 1, nums.end());
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

  Solution *s = new (Solution);
  s->nextPermutation(nums);
  for (int i = 0; i < (int)nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << "\n";

  return 0;
}
