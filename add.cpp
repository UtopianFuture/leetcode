#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int add(int a, int b) {
    while (b) { // if carry bit isn't zero, do  a ^= b again.
      int c = (unsigned int)(a & b) << 1; // carry bit
      a ^= b;                             // sum without carry bit
      b = c;
    }
    return a;
  }
};

int main(int argc, char *argv[]) { return 0; }
