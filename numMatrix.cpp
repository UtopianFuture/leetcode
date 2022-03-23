#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class NumMatrix {
  vector<vector<int>> sums;

public:
  NumMatrix(vector<vector<int>> &matrix) {
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();
    this->sums.resize(row, vector<int>(col + 1));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        sums[i][j + 1] = sums[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int res = 0;
    int tmp;
    for (int i = row1; i <= row2; i++) {
      tmp = sums[i][col2 + 1] - sums[i][col1];
      res += tmp;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int row, col;
  cin >> row >> col;
  vector<vector<int>> matrix(row, vector<int>(col));
  int tmp;
  vector<int> tmp_m;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> tmp;
      tmp_m.push_back(tmp);
    }
    matrix.push_back(tmp_m);
    tmp_m.clear();
  }

  int row1, col1, row2, col2;
  cin >> row1 >> col1 >> row2 >> col2;
  NumMatrix *obj = new NumMatrix(matrix);
  cout << obj->sumRegion(row1, col1, row2, col2) << "\n";

  return 0;
}
