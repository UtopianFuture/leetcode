#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
  int m, n;
  vector<vector<int>> grid;

public:
  bool isVaild(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

  void dfs(int a, int b) {
    if (isVaild(a, b)) {
      if (this->grid[a][b] == 1) {
        this->grid[a][b] = 0;
      } else {
        return;
      }
    } else {
      return;
    }

    dfs(a - 1, b);
    dfs(a + 1, b);
    dfs(a, b + 1);
    dfs(a, b - 1);
  }

  int numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    this->m = m;
    this->n = n;
    this->grid = grid;

    for (int i = 0; i < n; i++) {
      if (grid[0][i]) {
        dfs(0, i);
      }
      if (grid[m - 1][i]) {
        dfs(m - 1, i);
      }
    }

    for (int i = 1; i < m - 1; i++) {
      if (grid[i][0]) {
        dfs(i, 0);
      }
      if (grid[i][n - 1]) {
        dfs(i, n - 1);
      }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (this->grid[i][j]) {
          res++;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->numEnclaves(grid) << endl;
  return 0;
}
