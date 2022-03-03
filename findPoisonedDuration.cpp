#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

bool cmp(const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }

class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int size = (int)timeSeries.size();
    vector<vector<int>> tmp;
    int res = 0;
    int max;
    for (int i = 0; i < size; i++) {
      tmp.push_back({timeSeries[i], timeSeries[i] + duration - 1});
    }
    for (int i = 0; i < (int)tmp.size();) {
      // the right endpoint
      max = tmp[i][1];
      int j = i + 1;
      while (j < (int)tmp.size() && tmp[j][0] <= max) {
        max = max > tmp[j][1] ? max : tmp[j][1];
        j++;
      }
      res += (max - tmp[i][0] + 1);
      i = j;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  vector<int> timeSeries;
  int tmp1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp1;
    timeSeries.push_back(tmp1);
  }
  int duration;
  cin >> duration;

  Solution *s = new (Solution);
  int res = s->findPoisonedDuration(timeSeries, duration);
  cout << res << "\n";

  return 0;
}
