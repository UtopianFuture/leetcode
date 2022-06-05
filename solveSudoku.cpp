#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isVaild(vector<vector<char>> &board, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
      if (board[r][i] == ch) {
        return false;
      }
      if (board[i][c] == ch) {
        return false;
      }
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) {
        return false;
      }
    }
    return true;
  }

  bool backtrace(vector<vector<char>> &board, int i, int j) {
    int m = 9, n = 9;
    if (j == n) { // the last column
      return backtrace(board, i + 1, 0);
    }
    if (i == m) {
      // this is a solution
      return true;
    }

    if (board[i][j] != '.') {
      // this space has number
      return backtrace(board, i, j + 1);
    }

    for (char ch = '1'; ch <= '9'; ch++) {
      // check every number
      if (!isVaild(board, i, j, ch)) {
        continue;
      }
      board[i][j] = ch;
      if (backtrace(board, i, j + 1)) {
        return true;
      }
      board[i][j] = '.';
    }
    return false;
  }

  void solveSudoku(vector<vector<char>> &board) { backtrace(board, 0, 0); }
};

int main(int argc, char *argv[]) { return 0; }
