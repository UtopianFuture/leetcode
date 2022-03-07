#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
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
  cout << s->removeDuplicates(nums) << "\n";

  return 0;
}
