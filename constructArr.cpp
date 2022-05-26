#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> constructArr(vector<int> &a) {
    int n = a.size();
    if (n == 0) {
      return vector<int>{};
    }
    if (n == 1) {
      return vector<int>{1};
    }
    vector<int> res(n, 1);
    int tmp = 1;
    for (int i = 1; i < n; i++) {
      tmp *= a[i - 1];
      res[i] = tmp;
    }
    tmp = 1;
    for (int i = n - 2; i >= 0; i--) {
      tmp *= a[i + 1];
      res[i] *= tmp;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
