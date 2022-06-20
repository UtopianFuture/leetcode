#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  unordered_map<string, vector<int>> map;

public:
  vector<int> diffWaysToCompute(string expression) {
    if (map.find(expression) != map.end()) {
      return map[expression];
    }

    vector<int> res;
    for (int i = 0; i < (int)expression.size(); i++) {
      char c = expression[i];
      if (c == '+' || c == '-' || c == '*') {
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right = diffWaysToCompute(
            expression.substr(i + 1, (int)expression.size() - i));

        for (int m = 0; m < (int)left.size(); m++) {
          for (int n = 0; n < (int)right.size(); n++) {
            if (c == '+') {
              res.push_back(left[m] + right[n]);
            } else if (c == '-') {
              res.push_back(left[m] - right[n]);
            } else if (c == '*') {
              res.push_back(left[m] * right[n]);
            }
          }
        }
      }
    }
    if (res.empty()) {
      return vector<int>{stoi(expression)};
    }
    if (map.find(expression) == map.end()) {
      map[expression] = res;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string expression;
  cin >> expression;

  Solution *s = new Solution;
  vector<int> res = s->diffWaysToCompute(expression);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
