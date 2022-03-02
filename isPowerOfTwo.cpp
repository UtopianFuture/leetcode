#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n == 0) {
      return false;
    }
    int res = 0;
    long tmp = n;
    while (tmp != 0) {
      tmp &= (tmp - 1);
      res++;
      if (res == 1) {
        break;
      }
    }
    return tmp == 0;
  }
};

int main(int argc, char *argv[]) { return 0; }
