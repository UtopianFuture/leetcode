#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
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

  int nthUglyNumber(int n) {
    int count = 0;
    int i = 0;
    while (1) {
      if (isUgly(i)) {
        count++;
      }
      if (count == n) {
        return i;
      }
      i++;
    }
  }
};

class Solution2 {
public:
  int nthUglyNumber(int n) {
    int dp[n + 1];
    dp[1] = 1;
    int val1, val2;
    int p2 = 1, p3 = 1, p5 = 1;
    int tmp2, tmp3, tmp5;
    for (int i = 2; i <= n; i++) {
      tmp2 = 2 * dp[p2];
      tmp3 = 3 * dp[p3];
      tmp5 = 5 * dp[p5];
      val1 = tmp2 < tmp3 ? tmp2 : tmp3;
      val2 = val1 < tmp5 ? val1 : tmp5;
      dp[i] = val2;
      if (val2 == tmp2) {
        p2++;
      }
      if (val2 == tmp3) {
        p3++;
      }
      if (val2 == tmp5) {
        p5++;
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  // Solution1 *s = new (Solution1);
  Solution2 *s = new (Solution2);
  cout << s->nthUglyNumber(n) << "\n";

  return 0;
}
