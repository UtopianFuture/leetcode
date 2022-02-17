#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isConflict(vector<string> row, int nrow, int col, int n) {
    for (int i = 0; i < n; i++) {
      // check is this column has conflict
      if (row[i][col] == 'Q') {
        return false;
      }
      // check is this row has conflict
      if (row[nrow][i] == 'Q') {
        return false;
      }
    }
    // check 45 degree has conflict
    for (int i = nrow - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (row[i][j] == 'Q') {
        return false;
      }
    }
    // check 135 degree has conflict
    for (int i = nrow - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (row[i][j] == 'Q') {
        return false;
      }
    }
    // check 225 degree has conflict
    for (int i = nrow + 1, j = col - 1; i < n && j >= 0; i++, j--) {
      if (row[i][j] == 'Q') {
        return false;
      }
    }
    // check 315 degree has conflict
    for (int i = nrow + 1, j = col + 1; i < n && j < n; i++, j++) {
      if (row[i][j] == 'Q') {
        return false;
      }
    }

    return true;
  }

  void backtrace(vector<vector<string>> &board, vector<string> &row, int nrow,
                 int n) {
    // already arrive the last row
    if (nrow == n) {
      board.emplace_back(row);
      return;
    }

    string tmp = ".";
    for (int col = 0; col < n; col++) {
      // check conflict if row[nrow][col] = Q
      if (!isConflict(row, nrow, col, n)) {
        continue;
      }
      // if don't have conflict
      row[nrow][col] = 'Q';
      backtrace(board, row, nrow + 1, n);
      // this column has tried, recover to '.'
      row[nrow][col] = '.';
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> row(n, string(n, '.'));
    vector<vector<string>> board;
    backtrace(board, row, 0, n);
    return board;
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
