#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int strToInt(string str) {
    int n = (int)str.size();
    long res = 0;
    int i = 0;
    bool is_nega = false, is_zero = false;
    while (str[i] == ' ') {
      i++;
    }
    while (str[i] == '0') {
      i++;
      is_zero = true;
    }
    if (str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) {
      return 0;
    }

    if (str[i] == '-') {
      if (is_zero) {
        return 0;
      }
      is_nega = true;
      i++;
    } else if (str[i] == '+') {
      if (is_zero) {
        return 0;
      }
      is_nega = false;
      i++;
    }

    while (str[i] == '0') {
      i++;
    }

    int start = i;
    for (; i < n; i++) {
      if (!(str[i] >= '0' && str[i] <= '9')) {
        break;
      }
    }

    string substr = str.substr(start, i - start);
    if (substr.length() > 10) {
      if (is_nega) {
        return INT_MIN;
      } else {
        return INT_MAX;
      }
    }
    i = substr.length() - 1;
    long digit = 1;
    int tmp = 0;
    while (i >= 0) {
      tmp = substr[i] - '0';
      res += tmp * digit;
      digit *= 10;
      i--;
    }

    if (is_nega) {
      res = -res;
    }
    if (res > INT_MAX) {
      return INT_MAX;
    }
    if (res < INT_MIN) {
      return INT_MIN;
    }
    return (int)res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string str;
  cin >> str;

  Solution *s = new Solution;
  cout << s->strToInt(str) << "\n";
  return 0;
}
