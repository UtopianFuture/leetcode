#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
  int res = 0;

public:
  int sumNums(int n) {
    // bool x = (n > 1 && sumNums(n - 1));
    res += n;
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
