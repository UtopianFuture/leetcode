#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string intToRoman(int num) {
    string res;
    while (num > 0) {
      if (num >= 1000) {
        res.push_back('M');
        num -= 1000;
      } else if (num < 1000 && num >= 900) {
        res.push_back('C');
        res.push_back('M');
        num -= 900;
      } else if (num < 900 && num >= 500) {
        res.push_back('D');
        num -= 500;
      } else if (num < 500 && num >= 400) {
        res.push_back('C');
        res.push_back('D');
        num -= 400;
      } else if (num < 400 && num >= 100) {
        res.push_back('C');
        num -= 100;
      } else if (num < 100 && num >= 90) {
        res.push_back('X');
        res.push_back('C');
        num -= 90;
      } else if (num < 90 && num >= 50) {
        res.push_back('L');
        num -= 50;
      } else if (num < 50 && num >= 40) {
        res.push_back('X');
        res.push_back('L');
        num -= 40;
      } else if (num < 40 && num >= 10) {
        res.push_back('X');
        num -= 10;
      } else if (num < 10 && num >= 9) {
        res.push_back('I');
        res.push_back('X');
        num -= 9;
      } else if (num < 9 && num >= 5) {
        res.push_back('V');
        num -= 5;
      } else if (num < 5 && num >= 4) {
        res.push_back('I');
        res.push_back('V');
        num -= 4;
      } else if (num < 4 && num >= 1) {
        res.push_back('I');
        num--;
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
  cout << s->intToRoman(n) << endl;
  return 0;
}
