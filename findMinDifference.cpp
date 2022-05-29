#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int transfer(string s) {
    if ((int)s.size() != 5) {
      return -1;
    }

    int res = 0;
    res = (s[4] - '0') + (s[3] - '0') * 10 +
          ((s[1] - '0') + (s[0] - '0') * 10) * 60;
    return res;
  }

  int findMinDifference(vector<string> &timePoints) {
    int n = (int)timePoints.size();
    sort(timePoints.begin(), timePoints.end(), less<string>());
    int res = INT_MAX;
    int time1 = transfer(timePoints[0]);
    int time2;
    for (int i = 1; i < n; i++) {
      time2 = transfer(timePoints[i]);
      res = min(res, abs(time2 - time1));
      time1 = time2;
    }

    res = min(res, (1440 - time1) + transfer(timePoints[0]));
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<string> timePoints(n);
  for (int i = 0; i < n; i++) {
    cin >> timePoints[i];
  }

  Solution *s = new Solution;
  cout << s->findMinDifference(timePoints) << "\n";
  return 0;
}
