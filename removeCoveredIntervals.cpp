#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

  bool isCover(vector<int> a, vector<int> b) {
    return a[0] <= b[0] && a[1] >= b[1];
  }

  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int start = intervals[0][0], end = intervals[0][1];
    int n = (int)intervals.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
      if (isCover({start, end}, intervals[i])) {
        count++;
      } else if (isCover(intervals[i], {start, end})) {
        count++;
        start = intervals[i][0];
        end = intervals[i][1];
      } else {
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }
    return n - count;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>(2, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> intervals[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->removeCoveredIntervals(intervals) << endl;
  return 0;
}
