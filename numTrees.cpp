#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
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

class Solution {
private:
  vector<vector<int>> dp;

public:
  int calculate(int left, int right) {
    if (left >= right) {
      return 1;
    }

    if (dp[left][right] != 0) {
      return dp[left][right];
    }

    int res = 0;
    for (int i = left; i <= right; i++) {
      int lchild = calculate(left, i - 1);
      int rchild = calculate(i + 1, right);
      res += lchild * rchild;
    }
    dp[left][right] = res;
    return res;
  }

  int numTrees(int n) {
    dp.resize(n + 1, vector<int>(n + 1, 0));
    return calculate(1, n);
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
