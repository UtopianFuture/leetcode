#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution1 {
public:
  bool isPrime(int k) {
    int n = sqrt(k);
    for (int i = 2; i <= n; i++) {
      if (k % i == 0) {
        return false;
      }
    }
    return true;
  }

  int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime(i)) {
        count++;
      }
    }
    return count;
  }
};

class Solution2 {
public:
  int countPrimes(int n) {
    int count = 0;
    bool isPrime[n];
    memset(isPrime, 1, sizeof(isPrime));
    int tmp = sqrt(n);
    for (int i = 2; i <= tmp; i++) {
      if (isPrime[i]) {
        for (int j = i * i; j < n; j += i) {
          isPrime[j] = 0;
        }
      }
    }

    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        count++;
      }
    }

    return count;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  // Solution1 *s = new (Solution1);
  Solution2 *s = new (Solution2);
  cout << s->countPrimes(n) << "\n";

  return 0;
}
