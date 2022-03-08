#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    int dp[n + 1];
    dp[1] = 1;
    int size = (int)primes.size();
    int p[size];
    for (int i = 0; i < size; i++) {
      p[i] = 1;
    }
    // memset(p, 1, sizeof(p));
    int val[size];
    int min_val = 0x7fffffff;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < size; j++) {
        val[j] = dp[p[j]] * primes[j];
        if (min_val > val[j]) {
          min_val = val[j];
        }
      }
      dp[i] = min_val;
      min_val = 0x7fffffff;
      for (int k = 0; k < size; k++) {
        if (dp[i] == val[k]) {
          p[k]++;
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> primes;
  int tmp;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    primes.push_back(tmp);
  }
  Solution *s = new (Solution);
  cout << s->nthSuperUglyNumber(n, primes) << "\n";

  return 0;
}
