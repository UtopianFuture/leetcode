#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    int size = (int)nums.size();
    int target = size / 2;
    for (int i = 0; i < size; i++) {
      m[nums[i]]++;
      if (m[nums[i]] > target) {
        return nums[i];
      }
    }
    return nums[0];
  }
};

int main(int argc, char *argv[]) { return 0; }
