#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    for (int i = 1; i < (int)nums.size(); i++) {
      nums[0] ^= nums[i];
    }
    return nums[0];
  }
};

int main(int argc, char *argv[]) { return 0; }
