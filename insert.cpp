#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> res;
    int max;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 0; i < (int)intervals.size();) {
      // the right endpoint
      max = intervals[i][1];
      int j = i + 1;
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
  vector<int> newInterval;
  cin >> tmp1 >> tmp2;
  newInterval.push_back(tmp1);
  newInterval.push_back(tmp2);

  Solution *s = new (Solution);
  vector<vector<int>> res = s->insert(intervals, newInterval);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i][0] << " " << res[i][1] << "\n";
  }

  return 0;
}
