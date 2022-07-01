#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    int n = dist.size();
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
      time[i] = (dist[i] - 1) / speed[i];
    }

    sort(time.begin(), time.end(), less<int>());
    for (int i = 0; i < n; i++) {
      if (time[i] < i) {
        return i;
      }
    }
    return n;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> dist(n);
  vector<int> speed(n);
  for (int i = 0; i < n; i++) {
    cin >> dist[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> speed[i];
  }

  Solution *s = new Solution;
  cout << s->eliminateMaximum(dist, speed) << endl;
  return 0;
}
