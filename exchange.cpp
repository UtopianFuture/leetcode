#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> exchange(vector<int> &nums) {
    int size = nums.size();
    vector<int> res(size, 0);
    int head = 0, tail = size - 1;

    for (int i = 0; i < size; i++) {
      if (nums[i] % 2) {
        res[head++] = nums[i];
      } else {
        res[tail--] = nums[i];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
