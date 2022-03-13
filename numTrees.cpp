#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int numTrees(int n) {
    vector<int> G(n + 1, 0);
    G[0] = 1, G[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        G[i] += G[j - 1] * G[i - j];
      }
    }
    return G[n];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  cout << s->numTrees(n) << "\n";

  return 0;
}
