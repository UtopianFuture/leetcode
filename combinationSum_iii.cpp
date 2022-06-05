#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> res;
  int k, n;

public:
  void backtrace(vector<int> tmp, int sum, int start, int end) {
    if ((int)tmp.size() == k) {
      if (sum == n) {
        res.push_back(tmp);
      }
      return;
    }

    for (int i = start; i < end; i++) {
      sum += i;
      tmp.push_back(i);
      backtrace(tmp, sum, i + 1, end);
      tmp.pop_back();
      sum -= i;
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    this->k = k;
    this->n = n;
    vector<int> tmp;
    int sum = 0;
    backtrace(tmp, sum, 1, 10);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int k, n;
  cin >> k >> n;

  Solution *s = new Solution;
  vector<vector<int>> res = s->combinationSum3(k, n);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  return 0;
}
