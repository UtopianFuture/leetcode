#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isEating(vector<int> &piles, int h, int k) {
    int count = 0;
    int size = (int)piles.size();
    for (int i = 0; i < size; i++) {
      if (piles[i] % k == 0) {
        count += piles[i] / k;
      } else {
        count += piles[i] / k + 1;
      }
    }
    return count <= h;
  }

  int minEatingSpeed(vector<int> &piles, int h) {
    int size = (int)piles.size();
    int mid = 1, left = 1, right = 0;
    int max = 0;
    for (int i = 0; i < size; i++) {
      max = max > piles[i] ? max : piles[i];
    }
    right = max;

    if (h == size) {
      return right;
    }

    while (left < right) {
      mid = (left + right) / 2;
      // K = mid, can finish
      if (isEating(piles, h, mid)) {
        right = mid - 1;
      } else { // can't finish
        left = mid + 1;
      }
    }

    if (!isEating(piles, h, left)) {
      int i = left + 1;
      while (i < max) {
        if (isEating(piles, h, i)) {
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
  int n, h;
  cin >> n;
  int tmp;
  vector<int> piles;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    piles.push_back(tmp);
  }
  cin >> h;
  Solution *s = new (Solution);
  cout << s->minEatingSpeed(piles, h) << "\n";

  return 0;
}
