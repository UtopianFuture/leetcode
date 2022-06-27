#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int m, n;
  vector<vector<int>> grid;

public:
  bool isVaild(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

  void dfs(int a, int b) {
    if (isVaild(a, b)) {
      if (this->grid[a][b] == 0) {
        this->grid[a][b] = 1;
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

  int closedIsland(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    this->m = m;
    this->n = n;
    this->grid = grid;

    for (int i = 0; i < n; i++) {
      if (!grid[0][i]) {
        dfs(0, i);
      }
      if (!grid[m - 1][i]) {
        dfs(m - 1, i);
      }
    }

    for (int i = 1; i < m - 1; i++) {
      if (!grid[i][0]) {
        dfs(i, 0);
      }
      if (!grid[i][n - 1]) {
        dfs(i, n - 1);
      }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (this->grid[i][j] == 0) {
          res++;
          dfs(i, j);
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
