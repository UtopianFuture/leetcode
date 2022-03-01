#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool inArea(vector<vector<int>> &grid, int row, int col) {
    return row >= 0 && row < (int)grid.size() && col >= 0 &&
           col < (int)grid[0].size();
  }

  int DFS(vector<vector<int>> &grid, int row, int col) {
    if (!inArea(grid, row, col)) {
      return 0;
    }
    if (grid[row][col] == 0 || grid[row][col] == 2) {
      return 0;
    }

    // this element has visited
    grid[row][col] = 2;
    return 1 + DFS(grid, row + 1, col) + DFS(grid, row, col + 1) +
           DFS(grid, row - 1, col) + DFS(grid, row, col - 1);
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max = 0;
    int area;
    for (int i = 0; i < (int)grid.size(); i++) {
      for (int j = 0; j < (int)grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          area = DFS(grid, i, j);
          max = max > area ? max : area;
        }
      }
    }
    return max;
  }
};

int main(int argc, char *argv[]) { return 0; }
