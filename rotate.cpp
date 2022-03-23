#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int tmp;
    int n = (int)matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }

    for (int i = 0; i < n; i++) {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
