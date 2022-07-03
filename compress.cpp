#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int compress(vector<char> &chars) {
    int count = 0;
    char cur;
    string tmp;
    while (!chars.empty()) {
      count = 0;
      cur = chars.front();
      while (!chars.empty() && cur == chars.front()) {
        count++;
        chars.erase(chars.begin(), chars.begin() + 1);
      }
      tmp.push_back(cur);
      if (count != 1) {
        tmp += to_string(count);
      }
    }

    for (int i = 0; i < tmp.size(); i++) {
      chars.push_back(tmp[i]);
    }
    return tmp.size();
  }
};

int main(int argc, char *argv[]) {}
