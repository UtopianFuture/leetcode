#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  long dfs(int times, long n) {
    if (n == 1) {
      return times;
    }

    if (n % 2 == 1) {
      return min(dfs(times + 1, n + 1), dfs(times + 1, n - 1));
    } else {
      return dfs(times + 1, n / 2);
    }
  }

  int integerReplacement(int n) { return dfs(0, n); }
};

int main(int argc, char *argv[]) { return 0; }
