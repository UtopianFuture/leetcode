#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int base = 1337;

public:
  long myPow(int a, int b) {
    long res = 1;
    for (int i = 0; i < b; i++) {
      res = res * a % base;
    }
    return res;
  }

  int superPow(int a, vector<int> &b) {
    long res = 1;
    for (int i = (int)b.size() - 1; i >= 0; i--) {
      res = res * myPow(a, b[i]) % base;
      a = myPow(a, 10);
    }
    return (int)res;
  }
};

int main(int argc, char *argv[]) { return 0; }
