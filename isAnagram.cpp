#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> ms, mt;
    int ns = (int)s.size();
    int nt = (int)t.size();
    if (ns != nt) {
      return false;
    }

    for (int i = 0; i < nt; i++) {
      ms[s[i]]++;
      mt[t[i]]++;
    }

    for (int i = 0; i < nt; i++) {
      if (ms[s[i]] != mt[s[i]]) {
        return false;
      }
    }

    for (int i = 0; i < nt; i++) {
      if (s[i] != t[i]) {
        return true;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string s, t;
  cin >> s >> t;

  Solution *so = new Solution;
  cout << (bool)so->isAnagram(s, t) << "\n";
  return 0;
}
