#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int row = (int)matrix.size();
    int col = (int)matrix[0].size();
    int n = row * col;
    vector<int> res;
    int count = 0;
    int upper_bound = 0, lower_bound = row - 1;
    int left_bound = 0, right_bound = col - 1;
    while (count < n) {
      if (upper_bound <= lower_bound) {
        for (int i = left_bound; i <= right_bound; i++) {
          count++;
          res.push_back(matrix[upper_bound][i]);
        }
        upper_bound++;
      }

      if (left_bound <= right_bound) {
        for (int i = upper_bound; i <= lower_bound; i++) {
          count++;
          res.push_back(matrix[i][right_bound]);
        }
        right_bound--;
      }

      if (upper_bound <= lower_bound) {
        for (int i = right_bound; i >= left_bound; i--) {
          count++;
          res.push_back(matrix[lower_bound][i]);
        }
        lower_bound--;
      }

      if (left_bound <= right_bound) {
        for (int i = lower_bound; i >= upper_bound; i--) {
          count++;
          res.push_back(matrix[i][left_bound]);
        }
        left_bound++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int row, col;
  cin >> row >> col;
  vector<vector<int>> matrix;
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

  int n;
  cin >> n;
  Solution *obj = new Solution;
  vector<int> res = obj->spiralOrder(matrix);
  for (int i = 0; i < (int)res.size(); i++)
    cout << res[i] << "\n";

  return 0;
}
