#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  double quickMul(double x, long n) {
    if (n == 0) {
      return 1.0;
    }
    double res = quickMul(x, n / 2);
    return n % 2 == 1 ? res * res * x : res * res;
  }

  double myPow(double x, int n) {
    long tmp = n;
    return tmp >= 0 ? quickMul(x, tmp) : 1.0 / quickMul(x, -tmp);
  }
};

int main(int argc, char *argv[]) { return 0; }
