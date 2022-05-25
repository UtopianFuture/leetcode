#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    unordered_map<int, int> m;
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
      m[nums[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (m[nums[i]] == 1) {
        return nums[i];
      }
    }
    return nums[0];
  }
};

int main(int argc, char *argv[]) { return 0; }
