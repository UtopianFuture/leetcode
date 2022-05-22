#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string replaceSpace(string s) {
    int size = s.size();
    string res;
    string target = "%20";
    for (int i = 0; i < size; i++) {
      if (s[i] == ' ') {
        res += target;
      } else {
        res += s[i];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  string str;
  char tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    str.push_back(tmp);
  }

  Solution *s = new Solution;
  cout << s->replaceSpace(str) << "\n";
  return 0;
}
