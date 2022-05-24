#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  char firstUniqChar(string s) {
    unordered_map<int, int> res;
    int n = (int)s.length();
    for (int i = 0; i < n; i++) {
      res[s[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (res[s[i]] == 1) {
        return s[i];
      }
    }
    return ' ';
  }
};

int main(int argc, char *argv[]) { return 0; }
