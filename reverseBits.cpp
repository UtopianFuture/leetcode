#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int tmp = 0;
    while (n != 0) {
      res += (n & 1) << (31 - tmp);
      n = n >> 1;
      tmp++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  uint32_t n;
  cin >> n;
  Solution *s = new (Solution);
  cout << s->reverseBits(n) << "\n";
  
  return 0;
}
