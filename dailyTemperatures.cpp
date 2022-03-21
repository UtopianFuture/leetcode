#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int size = (int)temperatures.size();
    stack<vector<int>> s;
    vector<int> res(size, 0);
    for (int i = size - 1; i >= 0; i--) {
      while (!s.empty() && s.top()[0] <= temperatures[i]) {
        s.pop();
      }
      res[i] = s.empty() ? 0 : s.top()[1] - i;
      s.push({temperatures[i], i});
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> temperatures;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    temperatures.push_back(tmp);
  }

  Solution *s = new Solution;
  vector<int> res = s->dailyTemperatures(temperatures);
  for (int i = 0; i < n; i++) {
    cout << res[i] << "\n";
  }
  return 0;
}
