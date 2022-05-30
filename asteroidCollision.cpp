#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    for (int i = 0; i < (int)asteroids.size() - 1; i++) {
      if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
        if (asteroids[i] > abs(asteroids[i + 1])) {
          asteroids.erase(asteroids.begin() + i + 1, asteroids.begin() + i + 2);
        } else if (asteroids[i] < abs(asteroids[i + 1])) {
          asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 1);
          i--;
        } else {
          asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
          i--;
        }
        if (i > -1) {
          i--;
        }
      }
    }
    return asteroids;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> asteroids(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> asteroids[i];
  }

  Solution *s = new Solution;
  vector<int> res = s->asteroidCollision(asteroids);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
