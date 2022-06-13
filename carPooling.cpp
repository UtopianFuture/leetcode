#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> res;
    int n = 1001;
    res.resize(n);
    int max = 0;
    int size = (int)trips.size();
    for (int i = 0; i < size; i++) {
      res[trips[i][1]] += trips[i][0];
      max = max > trips[i][2] ? max : trips[i][2];
      if (trips[i][1] != n) {
        res[trips[i][2]] -= trips[i][0];
      }
    }

    if (res[0] > capacity) {
      return false;
    }
    for (int i = 1; i < max; i++) {
      res[i] += res[i - 1];
      if (res[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};

class Solution1 {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    int n = (int)trips.size();
    vector<int> res(1001, 0);

    int m = INT_MIN;
    for (int i = 0; i < n; i++) {
      res[trips[i][1]] += trips[i][0];
      if (trips[i][1] != 1000) {
        res[trips[i][2]] -= trips[i][0];
      }
      m = max(m, trips[i][2]);
    }

    if (res[0] > capacity) {
      return false;
    }
    for (int i = 1; i < m; i++) {
      res[i] += res[i - 1];
      if (res[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int size;
  cin >> size;
  vector<vector<int>> trips;
  int tmp;
  vector<int> tmp_m;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tmp;
      tmp_m.push_back(tmp);
    }
    trips.push_back(tmp_m);
    tmp_m.clear();
  }

  int n;
  cin >> n;
  Solution *obj = new Solution;
  cout << obj->carPooling(trips, n) << "\n";

  return 0;
}
