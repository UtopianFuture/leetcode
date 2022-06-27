#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isVaild(vector<vector<char>> board, int m, int n) {
    for (int i = 0; i < 9; i++) {
      if (i != n && board[m][i] == board[m][n]) {
        return false;
      }
      if (i != m && board[i][n] == board[m][n]) {
        return false;
      }
    }

    int xbase = m / 3 * 3;
    int ybase = n / 3 * 3;
    for (int i = m - 1; i >= xbase; i--) {
      for (int j = n - 1; j >= ybase; j--) {
        if (board[i][j] == board[m][n]) {
          return false;
        }
      }
    }
    for (int i = m - 1; i >= xbase; i--) {
      for (int j = n + 1; j < ybase + 3; j++) {
        if (board[i][j] == board[m][n]) {
          return false;
        }
      }
    }
    for (int i = m + 1; i < xbase + 3; i++) {
      for (int j = n - 1; j >= ybase; j--) {
        if (board[i][j] == board[m][n]) {
          return false;
        }
      }
    }
    for (int i = m + 1; i < xbase + 3; i++) {
      for (int j = n + 1; j < ybase + 3; j++) {
        if (board[i][j] == board[m][n]) {
          return false;
        }
      }
    }
    return true;
  }

  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          if (!isVaild(board, i, j)) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
