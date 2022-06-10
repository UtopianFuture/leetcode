#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
public:
  int removeDuplicates(vector<int> &nums) {
    int max = 0x7fffffff;
    int size = (int)nums.size();
    for (int i = 0; i < size;) {
      int j = i + 2;
      while (j < size && nums[j] == nums[i]) {
        nums[j] = max;
        j++;
      }
      i = j - 1;
    }

    int k = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] != max) {
        nums[k++] = nums[i];
      }
    }

    return k;
  }
};

class Solution2 {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) {
      return 0;
    }
    int left = 0, right = 0;
    int count = 0;
    while (right < n) {
      if (nums[right] != nums[left]) {
        left++;
        nums[left] = nums[right];
      } else if (left < right && count < 2) {
        left++;
        nums[left] = nums[right];
      }
      right++;
      count++;
      if (right < n && nums[right] != nums[right - 1]) {
        count = 0;
      }
    }
    return left + 1;
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

  Solution2 *s = new Solution2;
  cout << s->removeDuplicates(nums) << "\n";

  return 0;
}
