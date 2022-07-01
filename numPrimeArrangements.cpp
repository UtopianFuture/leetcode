#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPrime(int n) {
    int tmp = sqrt(n);
    for (int i = 2; i <= tmp; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  int numPrimeArrangements(int n) {
    int m = 1e9 + 7;

    int num = 0;
    for (int i = 2; i <= n; i++) {
      if (isPrime(i)) {
        num++;
      }
    }

    long res = 1;
    for (int i = 2; i <= num; i++) {
      res *= i;
      res %= m;
    }

    for (int i = 2; i <= n - num; i++) {
      res *= i;
      res %= m;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->numPrimeArrangements(n) << endl;
  return 0;
}
