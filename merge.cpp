#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    int max;
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 0; i < (int)intervals.size();) {
      // the right endpoint
      max = intervals[i][1];
      int j = i + 1;
      // if next interval's left endpoint is less than max,
      // means this two intervals is overlap,
      // such as: [1,4], [2,3]
      // and we need to adjust the right endpoint to the larger one
      // of intervals[j][1] and intervals[j - 1][1]
      while (j < (int)intervals.size() && intervals[j][0] <= max) {
        max = max > intervals[j][1] ? max : intervals[j][1];
        j++;
      }
      res.push_back({intervals[i][0], max});
      i = j;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  vector<vector<int>> intervals;
  int tmp1, tmp2;
  cin >> n;
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    tmp.push_back(tmp1);
    tmp.push_back(tmp2);
    intervals.push_back(tmp);
    tmp.clear();
  }

  Solution *s = new (Solution);
  vector<vector<int>> res = s->merge(intervals);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i][0] << " " << res[i][1] << "\n";
  }

  return 0;
}
