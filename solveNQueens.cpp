#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<string>> res;

public:
  bool isConflict(vector<string> tmp, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
      if (tmp[i][col] == 'Q') {
        return false;
      }
    }
    for (int i = 0; i < col; i++) {
      if (tmp[row][i] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (tmp[i][j] == 'Q') {
        return false;
      }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (tmp[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }

  void backtrace(vector<string> tmp, int row, int n) {
    if (row == n) {
      res.push_back(tmp);
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!isConflict(tmp, row, i, n)) {
        continue;
      }
      tmp[row][i] = 'Q';
      backtrace(tmp, row + 1, n);
      tmp[row][i] = '.';
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> tmp(n, string(n, '.'));
    backtrace(tmp, 0, n);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n = 0;
  cin >> n;

  Solution *s = new (Solution);
  vector<vector<string>> board = s->solveNQueens(n);
  for (int i = 0; i < (int)board.size(); i++) {
    for (int j = 0; j < (int)board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    printf("\n");
  }

  return 0;
}
