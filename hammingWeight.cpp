#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    while (n != 0) {
      n &= (n - 1);
      res++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
