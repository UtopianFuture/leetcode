#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPossible(vector<int> &nums) {
    unordered_map<int, int> times, order;
    for (int num : nums) {
      times[num]++;
    }

    for (int num : nums) {
      if (times[num] == 0) {
        continue;
      }
      if (times[num] > 0 && order[num - 1] > 0) {
        times[num]--;
        order[num - 1]--;
        order[num]++;
      } else if (times[num] > 0 && times[num + 1] > 0 && times[num + 2] > 0) {
        times[num]--;
        times[num + 1]--;
        times[num + 2]--;
        order[num + 2]++;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
