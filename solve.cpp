#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool inArea(vector<vector<char>> &board, int row, int col) {
    return row >= 0 && row < (int)board.size() && col >= 0 &&
           col < (int)board[0].size();
  }

  void DFS(vector<vector<char>> &board, int row, int col) {
    if (!inArea(board, row, col)) {
      return;
    }
    if (board[row][col] == 'X' || board[row][col] == '2') {
      return;
    }

    // this element has visited
    board[row][col] = '2';
    DFS(board, row + 1, col);
    DFS(board, row, col + 1);
    DFS(board, row - 1, col);
    DFS(board, row, col - 1);
  }

  void solve(vector<vector<char>> &board) {
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < col; i++) {
      if (board[0][i] == 'O') {
        DFS(board, 0, i);
      }
      if (board[row - 1][i] == 'O') {
        DFS(board, row - 1, i);
      }
    }
    for (int i = 1; i < row - 1; i++) {
      if (board[i][0] == 'O') {
        DFS(board, i, 0);
      }
      if (board[i][col - 1] == 'O') {
        DFS(board, i, col - 1);
      }
    }

    for (int i = 0; i < (int)board.size(); i++) {
      for (int j = 0; j < (int)board[i].size(); j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
        if (board[i][j] == '2') {
          board[i][j] = 'O';
        }
      }
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
