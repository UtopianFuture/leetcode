#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int row, col;
  vector<vector<int>> grid;
  vector<int> res;

public:
  int dfs(int i, int j) {
    if (i == row) {
      return j;
    }

    int res = -1;
    if (grid[i][j] == 1) {
      if (j == col - 1) {
        return -1;
      } else if (grid[i][j + 1] == 1) {
        res = dfs(i + 1, j + 1);
      } else if (grid[i][j + 1] == -1) {
        return -1;
      }
    } else {
      if (j == 0) {
        return -1;
      } else if (grid[i][j - 1] == -1) {
        res = dfs(i + 1, j - 1);
      } else if (grid[i][j - 1] == 1) {
        return -1;
      }
    }
    return res;
  }

  vector<int> findBall(vector<vector<int>> &grid) {
    this->row = grid.size();
    this->col = grid[0].size();
    this->grid.assign(grid.begin(), grid.end());
    vector<int> res(col, -1);

    for (int i = 0; i < col; i++) {
      res[i] = dfs(0, i);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  Solution *s = new Solution;
  vector<int> res = s->findBall(grid);
  for (auto k : res) {
    cout << k << " ";
  }
  cout << endl;
  return 0;
}
