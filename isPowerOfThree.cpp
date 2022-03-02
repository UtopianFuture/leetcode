#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n == 0) {
      return false;
    }
    long tmp = 1;
    while (tmp < n) {
      tmp *= 3;
    }
    return tmp == n;
  }
};

int main(int argc, char *argv[]) { return 0; }
