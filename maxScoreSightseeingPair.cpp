#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    int m = values[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
      res = max(res, m + values[i] - i);
      m = max(m, values[i] + i);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
