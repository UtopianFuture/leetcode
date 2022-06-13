#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums.begin(), nums.end(), less<int>());
    return nums;
  }
};

int main(int argc, char *argv[]) { return 0; }
