#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<int> candidates;
  int target;
  vector<vector<int>> res;

public:
  void backtrace(vector<int> tmp, int sum, int start, int end) {
    if (sum >= target) {
      if (sum == target) {
        // for (int i = 0; i < (int)res.size(); i++) {
        // if (res[i] == tmp) {
        // return;
        // }
        // }
        res.push_back(tmp);
        return;
      } else {
        return;
      }
    }

    if (start == end) {
      if (sum == target) {
        res.push_back({candidates[start - 1]});
      }
      return;
    }

    for (int i = start; i < end; i++) {
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      sum += candidates[i];
      tmp.push_back(candidates[i]);
      backtrace(tmp, sum, i + 1, end);
      tmp.pop_back();
      sum -= candidates[i];
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end(), less<int>());
    this->candidates = candidates;
    this->target = target;
    vector<int> tmp;
    int sum = 0;
    int n = (int)candidates.size();
    backtrace(tmp, sum, 0, n);
    return res;
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
  vector<vector<int>> res = s->combinationSum2(candidates, target);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
