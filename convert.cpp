#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    int n = s.size();
    vector<vector<char>> tmp(numRows, vector<char>(n / 2, '#'));
    int count = 0;
    int row = 0, col = 0;
    while (count < n) {
      if (row == 0) {
        while (row < numRows) {
          tmp[row][col] = s[count];
          count++;
          row++;
        }
      } else if (row == numRows) {
        row--;
        while (row > 0) {
          row--;
          col++;
          tmp[row][col] = s[count];
          count++;
        }
        count--;
      }
    }

    string res;
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < n / 2; j++) {
        cout << tmp[i][j] << " ";
        if (tmp[i][j] != '#') {
          res.push_back(tmp[i][j]);
        }
      }
      cout << endl;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  string s;
  cin >> n;
  cin >> s;

  Solution *so = new Solution;
  cout << so->convert(s, n) << endl;
  return 0;
}
