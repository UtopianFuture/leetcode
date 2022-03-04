#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isMatch(vector<int> &weights, int days, int k) {
    int res = 1;
    int count = k;
    int size = (int)weights.size();
    int tmp;
    for (int i = 0; i < size; i++) {
      tmp = count - weights[i];
      if (tmp >= 0) {
        count = tmp;
      } else {
        count = k - weights[i];
        res++;
      }
    }
    return res <= days;
  }

  int shipWithinDays(vector<int> &weights, int days) {
    int size = (int)weights.size();
    int mid = 1, left = 1, right = 0;
    int max = 0, sum = 0;
    for (int i = 0; i < size; i++) {
      sum += weights[i];
      max = max > weights[i] ? max : weights[i];
    }
    // the smallest ship must large or equal the largest weight,
    // not so, can't finish job.
    left = max;
    // the larget ship can finish this job only once.
    right = sum;

    if (days == 1) {
      return right;
    }

    while (left < right) {
      mid = (left + right) / 2;
      // K = mid, can finish
      if (isMatch(weights, days, mid)) {
        right = mid - 1;
      } else { // can't finish
        left = mid + 1;
      }
    }

    if (!isMatch(weights, days, left)) {
      int i = left + 1;
      while (i < sum) {
        if (isMatch(weights, days, i)) {
          return i;
        }
        i++;
      }
    }
    return left;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, days;
  cin >> n;
  int tmp;
  vector<int> weights;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    weights.push_back(tmp);
  }
  cin >> days;
  Solution *s = new (Solution);
  cout << s->shipWithinDays(weights, days) << "\n";

  return 0;
}
