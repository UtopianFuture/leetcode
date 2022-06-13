#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int size;
  unordered_map<int, int> blackmap;

public:
  Solution(int n, vector<int> &blacklist) {
    this->size = n - (int)blacklist.size();
    for (int b : blacklist) {
      blackmap[b] = 1;
    }

    int last = n - 1;
    for (int b : blacklist) {
      if (b >= this->size) {
        continue;
      }

      // this number not in blacklist.
      while (blackmap.count(last)) {
        last--;
      }
      blackmap[b] = last;
      last--;
    }
  }

  int pick() {
    int index = rand() % this->size;
    if (blackmap[index]) {
      return blackmap[index];
    }
    return index;
  }
};

int main(int argc, char *argv[]) { return 0; }
