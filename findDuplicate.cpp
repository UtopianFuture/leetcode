#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  //   int findDuplicate(vector<int> &nums) {
  //     int n = (int)nums.size();
  //     for (int i = 0; i < n; i++) {
  //       for (int j = i + 1; j < n; j++) {
  //         if (nums[i] == nums[j]) {
  //           return nums[i];
  //         }
  //       }
  //     }
  //     return 0;
  //   }

  int findDuplicate(vector<int> &nums) {
    int one = 0, two = 0;
    do {
      one = nums[one];
      two = nums[nums[two]];
    } while (one != two);

    two = 0;
    while (one != two) {
      one = nums[one];
      two = nums[two];
    }
    return one;
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
  cout << s->findDuplicate(nums) << "\n";

  return 0;
}
