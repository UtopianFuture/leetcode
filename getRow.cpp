#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> res(rowIndex + 1);

    vector<int> res1 = {1};
    res[0] = res1;
    if (rowIndex == 0) {
      return res[0];
    }
    vector<int> res2 = {1, 1};
    res[1] = res2;
    if (rowIndex == 1) {
      return res[1];
    }

    for (int i = 2; i <= rowIndex; i++) {
      vector<int> resi(i + 1, 0);
      resi[0] = 1;
      resi[i] = 1;
      for (int j = 1; j < i; j++) {
        resi[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res[i] = resi;
    }
    return res[rowIndex];
  }
};

int main(int argc, char *argv[]) { return 0; }
