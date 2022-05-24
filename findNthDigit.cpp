#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findNthDigit(int n) {
    int res;
    int num, digit;
    if (n < 10) { // 0 ~ 9
      res = n;
    } else if (n < 190) { // 10 ~ 99
      n -= 10;
      num = 10 + n / 2;
      digit = n % 2;
      digit = 1 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 2890) { // 100 ~ 999
      n -= 190;
      num = 100 + n / 3;
      digit = n % 3;
      digit = 2 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 38890) { // 1000 ~ 9999
      n -= 2890;
      num = 1000 + n / 4;
      digit = n % 4;
      digit = 3 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 488890) { // 10000 ~ 99999
      n -= 38890;
      num = 10000 + n / 5;
      digit = n % 5;
      digit = 4 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 5888890) { // 100000 ~ 999999
      n -= 488890;
      num = 100000 + n / 6;
      digit = n % 6;
      digit = 5 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 68888890) { // 1000000 ~ 9999999
      n -= 5888890;
      num = 1000000 + n / 7;
      digit = n % 7;
      digit = 6 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else if (n < 788888890) { // 10000000 ~ 99999999
      n -= 68888890;
      num = 10000000 + n / 8;
      digit = n % 8;
      digit = 7 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    } else { // > 100000000
      n -= 788888890;
      num = 100000000 + n / 9;
      digit = n % 9;
      digit = 8 - digit;
      while (digit >= 0) {
        res = num % 10;
        num /= 10;
        digit--;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  cout << s->findNthDigit(n) << "\n";
  return 0;
}
