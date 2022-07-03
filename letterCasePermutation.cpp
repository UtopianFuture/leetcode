#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<string> res;

public:
  void dfs(int start, int end, string s) {
    if (start == end) {
      this->res.push_back(s);
      return;
    }

    string tmp = s;
    if (s[start] >= 'a' && s[start] <= 'z') {
      tmp[start] += ('A' - 'a');
      dfs(start + 1, end, tmp);
    } else if (s[start] >= 'A' && s[start] <= 'Z') {
      tmp[start] -= ('A' - 'a');
      dfs(start + 1, end, tmp);
    }
    dfs(start + 1, end, s);
  }

  vector<string> letterCasePermutation(string s) {
    dfs(0, s.size(), s);
    return this->res;
  }
};

int main(int argc, char *argv[]) { return 0; }
