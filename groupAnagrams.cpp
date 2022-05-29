#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    int n = (int)strs.size();
    string tmp;
    for (int i = 0; i < n; i++) {
      tmp = strs[i];
      sort(strs[i].begin(), strs[i].end(), less<char>());
      m[strs[i]].push_back(tmp);
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      res.push_back(it->second);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
