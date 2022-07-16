#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  unordered_map<string, int> map;
  int row, col;
  int k;
  int res;

public:
  bool isVaild(int i, int j) { return i < this->row && j < this->col; }

  void dfs(int n, int i, int j) {
    if (!isVaild(i, j)) {
      return;
    }
    if (map[to_string(i) + "," + to_string(j)] == 1) {
      return;
    }
    if (n > this->k) {
      return;
    }

    map[to_string(i) + "," + to_string(j)] = 1;
    this->res++;
    dfs(n + 1, i + 1, j);
    dfs(n + 1, i, j + 1);
  }

  int movingCount(int m, int n, int k) {
    this->row = m;
    this->col = n;
    this->k = k;
    this->res = 0;
    dfs(0, 0, 0);

    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int m, n, k;
  cin >> m >> n >> k;

  Solution *s = new Solution;
  cout << s->movingCount(m, n, k) << endl;
  return 0;
}
