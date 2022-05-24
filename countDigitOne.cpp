#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int countDigitOne(int n) {
    int res = 0, digit = 1;
    int high = n / 10, cur = n % 10, low = 0;
    while (high || cur) {
      if (cur == 0) {
        res += high * digit;
      } else if (cur == 1) {
        res += high * digit + low + 1;
      } else {
        res += (high + 1) * digit;
      }
      low += cur * digit;
      cur = high % 10;
      high /= 10;
      digit *= 10;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  cout << s->countDigitOne(n) << "\n";
  return 0;
}
