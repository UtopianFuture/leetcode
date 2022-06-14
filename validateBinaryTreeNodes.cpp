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
    this->count = n;
    this->parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    while (x != parent[x]) {
      x = parent[x];
    }
    return x;
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

  bool connected(int n, int m) {
    int rootn = find(n);
    int rootm = find(m);
    return rootn == rootm;
  }

  int _count() { return count; }
};

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        degree[leftChild[i]]++;
      }
      if (rightChild[i] != -1) {
        degree[rightChild[i]]++;
      }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 0) {
        if (root != -1) {
          return false; // only one root
        }
        root = i;
      } else if (degree[i] != 1) {
        return false; // no node has more than one indegree
      }
    }

    if (root == -1) {
      return false;
    }

    UnionFind *uf = new UnionFind;
    uf->UF(n);
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        // check if there is a cycle.
        if (uf->connected(i, leftChild[i])) {
          return false;
        }
        uf->_union(i, leftChild[i]);
      }
      if (rightChild[i] != -1) {
        if (uf->connected(i, rightChild[i])) {
          return false;
        }
        uf->_union(i, rightChild[i]);
      }
    }
    return uf->_count() == 1;
  }
};

int main(int argc, char *argv[]) { return 0; }
