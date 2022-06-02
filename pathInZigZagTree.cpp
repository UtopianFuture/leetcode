#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    while (label >= 1) {
      res.insert(res.begin(), label);
      label /= 2;

      int depth = (int)(log(label) / log(2));
      label = pow(2, depth + 1) - 1 - (label - pow(2, depth));
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  vector<int> res = s->pathInZigZagTree(n);
  for (auto v : res) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
