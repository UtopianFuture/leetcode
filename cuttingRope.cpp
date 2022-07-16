#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int cuttingRope(int n) {
    if (n <= 3) {
      return n - 1;
    }

    int res = 0;
    int num = n / 3;
    int yu = n % 3;
    if (yu == 0) {
      res = pow(3, num);
    } else if (yu == 1) {
      res = pow(3, num - 1) * 4;
    } else {
      res = pow(3, num) * 2;
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->cuttingRope(n) << endl;
  return 0;
}
