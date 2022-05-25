#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int lastRemaining(int n, int m) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
      res = (res + m) % i;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
