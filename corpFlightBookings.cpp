#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> res;
    res.resize(n);
    int size = (int)bookings.size();
    for (int i = 0; i < size; i++) {
      for (int j = bookings[i][0]; j <= bookings[i][1]; j++) {
        res[j - 1] += bookings[i][2];
      }
    }
    return res;
  }
};

class Solution1 {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> res;
    res.resize(n);
    int size = (int)bookings.size();
    for (int i = 0; i < size; i++) {
      res[bookings[i][0] - 1] += bookings[i][2];
      if (bookings[i][1] != n) {
        res[bookings[i][1]] -= bookings[i][2];
      }
    }
    for (int i = 1; i < n; i++) {
      res[i] += res[i - 1];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int size;
  cin >> size;
  vector<vector<int>> bookings;
  int tmp;
  vector<int> tmp_m;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tmp;
      tmp_m.push_back(tmp);
    }
    bookings.push_back(tmp_m);
    tmp_m.clear();
  }

  int n;
  cin >> n;
  Solution *obj = new Solution;
  vector<int> res = obj->corpFlightBookings(bookings, n);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << "\n";
  }

  return 0;
}
