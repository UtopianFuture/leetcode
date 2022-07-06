#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int n = s.size();
    vector<int> cost(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cost[i] = abs(s[i - 1] - t[i - 1]) + cost[i - 1];
    }

    int res = 0;
    int left = 0, right = 1;
    while (right <= n && left < right) {
      while (right <= n && cost[right] - cost[left] <= maxCost) {
        res = max(res, right - left);
        right++;
      }
      left++;
      while (left >= right) {
        right++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
