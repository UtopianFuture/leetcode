#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class UnionFind {
private:
  vector<int> parent;
  int count;

public:
  void UF(int n) {
    this->parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    this->count = n;
  }

  void _union(int n, int m) {
    int rootn = find(n);
    int rootm = find(m);
    if (rootn == rootm) {
      return;
    }
    parent[rootm] = rootn;
    count--;
  }

  int find(int x) {
    while (x != parent[x]) {
      x = parent[x];
    }
    return x;
  }

  bool connected(int n, int m) {
    int rootn = find(n);
    int rootm = find(m);
    return rootn == rootm;
  }

  int _count() { return count; }
};

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    UnionFind *uf = new UnionFind;
    uf->UF(26);
    int n = (int)equations.size();
    for (int i = 0; i < n; i++) {
      if (equations[i][1] == '=') {
        uf->_union(equations[i][0] - 'a', equations[i][3] - 'a');
      }
    }

    for (int i = 0; i < n; i++) {
      if (equations[i][1] == '!') {
        if (uf->connected(equations[i][0] - 'a', equations[i][3] - 'a')) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
