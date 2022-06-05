#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> res;
  int target;
  vector<int> candidates;

public:
  void backtrace(vector<int> tmp, int sum, int start, int end) {
    if (sum >= this->target) {
      if (sum == this->target) {
        res.push_back(tmp);
        return;
      } else {
        return;
      }
    }
    if (start == end) {
      if (sum == this->target) {
        res.push_back({this->candidates[start - 1]});
      }
      return;
    }

    for (int i = start; i < end; i++) {
      tmp.push_back(candidates[i]);
      sum += candidates[i];
      backtrace(tmp, sum, i, end);
      sum -= candidates[i];
      tmp.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    this->candidates = candidates;
    this->target = target;
    int n = (int)candidates.size();
    vector<int> tmp;
    int sum = 0;
    backtrace(tmp, sum, 0, n);
    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> candidates(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> candidates[i];
  }
  int target;
  cin >> target;

  Solution *s = new Solution;
  vector<vector<int>> res = s->combinationSum(candidates, target);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
