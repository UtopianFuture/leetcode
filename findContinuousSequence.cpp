#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    int sum = 0;
    int left = 1, right = 1;
    while (left < target && left <= right) {
      if (sum + right < target) {
        sum += right;
        tmp.push_back(right);
        right++;
      } else if (sum + right > target) {
        tmp.erase(tmp.begin(), tmp.begin() + 1);
        sum -= left;
        left++;
      } else { // sum + right == target
        tmp.push_back(right);
        res.push_back(tmp);
        sum -= left;
        left++;
        tmp.erase(tmp.begin(), tmp.begin() + 1);
        sum += right;
        right++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  vector<vector<int>> res = s->findContinuousSequence(n);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
