#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class UnionFind {
private:
  int count; // union number
  int *parent;

public:
  void UF(int n) {
    this->count = n;
    parent = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // union to node
  void _union(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) {
      return;
    }
    parent[rootp] = rootq;
    count--;
  }

  // if two node is connected
  bool connected(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    return rootp == rootq;
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  int _count() { return count; }
};

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    UnionFind *uf = new (UnionFind);
    uf->UF(26);
    int p, q;
    for (int i = 0; i < (int)equations.size(); i++) {
      if (equations[i][1] == '=') {
        p = equations[i][0] - 'a';
        q = equations[i][3] - 'a';
        uf->_union(p, q);
      }
    }

    for (int i = 0; i < (int)equations.size(); i++) {
      if (equations[i][1] == '!') {
        p = equations[i][0] - 'a';
        q = equations[i][3] - 'a';
        if (uf->connected(p, q)) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) { return 0; }
