#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> end(26, 0);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      end[s[i] - 'a'] = i;
    }

    vector<int> res;
    int start = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
      m = max(m, end[s[i] - 'a']);
      if (m == i) {
        res.push_back(i + 1 - start);
        start = i + 1;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
