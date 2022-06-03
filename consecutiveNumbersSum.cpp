#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int res = 1; // must include itself

public:
  int consecutiveNumbersSum(int n) {
    int right = n / 2 + 1;
    int left;
    int sum = 0;
    while (right > 1) {
      left = right - 1;
      sum = right;
      while (left > 0) {
        sum += left;
        if (sum == n) {
          res++;
          break;
        } else if (sum > n) {
          sum = 0;
          break;
        }
        left--;
      }
      right--;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->consecutiveNumbersSum(n) << "\n";
  return 0;
}
