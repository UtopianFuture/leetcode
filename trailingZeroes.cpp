#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int trailingZeroes(int n) {
    int divisor = 5;
    int res = 0;
    while (divisor <= n) {
      res += n / divisor;
      divisor *= 5;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
