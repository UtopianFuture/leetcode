#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> grid1, grid2;
  int row, col;
  bool flag;

public:
  bool isVaild(int i, int j) {
    return i >= 0 && i < this->row && j >= 0 && j < this->col;
  }

  void isSubIsland(int i, int j) {
    if (!isVaild(i, j)) {
      return;
    }

    if (this->grid2[i][j] != 1) {
      return;
    }

    if (this->grid1[i][j] != 1) {
      flag = 0;
    }

    this->grid2[i][j] = 2;

    isSubIsland(i + 1, j);
    isSubIsland(i - 1, j);
    isSubIsland(i, j + 1);
    isSubIsland(i, j - 1);
  }

  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    int res = 0;

    this->flag = 1;
    this->row = grid1.size();
    this->col = grid1[0].size();
    this->grid1 = grid1;
    this->grid2 = grid2;
    for (int i = 0; i < this->row; i++) {
      for (int j = 0; j < this->col; j++) {
        if (this->grid2[i][j] == 1) {
          isSubIsland(i, j);
          if (flag) {
            res++;
          }
          this->flag = 1;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
