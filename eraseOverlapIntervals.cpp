#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }

  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if (n == 0) {
      return 0;
    }
    sort(intervals.begin(), intervals.end(), cmp);

    int count = 1;
    int end = intervals[0][1];
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] >= end) {
        count++;
        end = intervals[i][1];
      }
    }
    return n - count;
  }
};

int main(int argc, char *argv[]) { return 0; }
