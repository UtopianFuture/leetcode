#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  long trailingZeroes(long n) {
    long divisor = 5;
    long res = 0;
    while (divisor <= n) {
      res += n / divisor;
      divisor *= 5;
    }
    return res;
  }

  long upper(int k) {
    long left = 0, right = 2 * (long)INT_MAX;
    long mid;
    long num_zero;
    while (left < right) {
      mid = (left + right) / 2;
      num_zero = trailingZeroes(mid);
      if (num_zero > k) {
        right = mid;
      } else if (num_zero <= k) {
        left = mid + 1;
      }
    }
    return left - 1;
  }

  long lower(int k) {
    long left = 0, right = 2 * (long)INT_MAX;
    long mid;
    long num_zero;
    while (left < right) {
      mid = (left + right) / 2;
      num_zero = trailingZeroes(mid);
      if (num_zero >= k) {
        right = mid;
      } else if (num_zero < k) {
        left = mid + 1;
      }
    }
    return left;
  }

  int preimageSizeFZF(int k) {
    long lower_bound = lower(k);
    long upper_bound = upper(k);
    return (int)(upper_bound - lower_bound + 1);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->preimageSizeFZF(n) << endl;
  return 0;
}
