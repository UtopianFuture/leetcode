#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int cur = 0;

public:
  int calculate(char ch, string ring) {
    int n = ring.size();
    if (ch == ring[cur]) {
      return 0;
    }
    int pos = INT_MAX;
    int dis = INT_MAX;
    int tmp, a;
    for (int i = 0; i < n; i++) {
      if (ch == ring[i]) {
        a = abs(cur - i);
        tmp = min(a, n - a);
        if (tmp < dis) {
          dis = tmp;
          pos = i;
        }
      }
    }
    this->cur = pos;
    return dis;
  }

  int findRotateSteps(string ring, string key) {
    // int n = ring.size();
    int m = key.size();
    int res = 0;
    for (int i = 0; i < m; i++) {
      res += calculate(key[i], ring) + 1;
    }
    return res;
  }
};

class Solution1 {
private:
  unordered_map<char, vector<int>> map;
  vector<vector<int>> dp;

public:
  int dfs(string ring, int m, string key, int n) {
    if (n == (int)key.size()) {
      return 0;
    }
    if (dp[m][n]) {
      return dp[m][n];
    }

    int length = ring.size();
    int res = INT_MAX;
    for (auto k : map[key[n]]) {
      int dis = abs(m - k);
      dis = min(dis, length - dis);
      int tmp = dfs(ring, k, key, n + 1);
      res = min(res, 1 + tmp + dis);
    }
    dp[m][n] = res;
    return dp[m][n];
  }

  int findRotateSteps(string ring, string key) {
    int m = ring.size();
    int n = key.size();
    for (int i = 0; i < m; i++) {
      map[ring[i]].push_back(i);
    }

    dp.resize(m, vector<int>(n));
    return dfs(ring, 0, key, 0);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string ring, key;
  cin >> ring >> key;

  Solution *s = new Solution;
  cout << s->findRotateSteps(ring, key) << endl;
  return 0;
}
