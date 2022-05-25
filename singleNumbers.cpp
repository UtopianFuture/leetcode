#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> singleNumbers(vector<int> &nums) {
    vector<int> res(2, 0);
    int tmp = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      tmp ^= nums[i];
    }
    int div = 1;
    while ((div & tmp) == 0) {
      div <<= 1;
    }

    for (int i = 0; i < n; i++) {
      if ((nums[i] & div) == 0) {
        res[0] ^= nums[i];
      } else {
        res[1] ^= nums[i];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
