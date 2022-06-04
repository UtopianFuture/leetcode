#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);

    vector<int> res1 = {1};
    res[0] = res1;
    if (numRows == 1) {
      return res;
    }
    vector<int> res2 = {1, 1};
    res[1] = res2;
    if (numRows == 2) {
      return res;
    }

    for (int i = 2; i < numRows; i++) {
      vector<int> resi(i + 1, 0);
      resi[0] = 1;
      resi[i] = 1;
      for (int j = 1; j < i; j++) {
        resi[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      res[i] = resi;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  s->generate(n);
  return 0;
}
