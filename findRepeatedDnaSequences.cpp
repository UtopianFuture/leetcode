#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> map;
    int n = s.size();
    vector<string> res;
    if (n <= 10) {
      return res;
    }
    string tmp;
    for (int i = 0; i < n - 10; i++) {
      tmp = s.substr(i, 10);
      if (map[tmp] == 1) {
        res.push_back(tmp);
      }
      map[tmp]++;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
