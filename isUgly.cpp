#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isUgly(int n) {
    if (n < 1) {
      return false;
    }
    while (n % 5 == 0) {
      n /= 5;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    while (n % 2 == 0) {
      n >>= 1;
    }
    return n == 1;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new (Solution);
  cout << s->isUgly(n) << "\n";

  return 0;
}
