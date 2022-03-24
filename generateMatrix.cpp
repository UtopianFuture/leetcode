#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int count = 1;
    int end = n * n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int upper_bound = 0, lower_bound = n - 1;
    int left_bound = 0, right_bound = n - 1;
    while (count <= end) {
      if (upper_bound <= lower_bound) {
        for (int i = left_bound; i <= right_bound; i++) {
          matrix[upper_bound][i] = count;
          count++;
        }
        upper_bound++;
      }

      if (left_bound <= right_bound) {
        for (int i = upper_bound; i <= lower_bound; i++) {
          matrix[i][right_bound] = count;
          count++;
        }
        right_bound--;
      }

      if (upper_bound <= lower_bound) {
        for (int i = right_bound; i >= left_bound; i--) {
          matrix[lower_bound][i] = count;
          count++;
        }
        lower_bound--;
      }

      if (left_bound <= right_bound) {
        for (int i = lower_bound; i >= upper_bound; i--) {
          matrix[i][left_bound] = count;
          count++;
        }
        left_bound++;
      }
    }
    return matrix;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  vector<vector<int>> res = s->generateMatrix(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
