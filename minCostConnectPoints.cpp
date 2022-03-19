#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class UnionFind {
private:
  vector<int> parent;
  // vector<int> rank;
  int count;

public:
  void UF(int n) {
    this->count = n;
    // rank.resize(n, 1);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int _union(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) {
      return false;
    }
    // if (rank[rootp] < rank[rootq]) {
    // swap(rootp, rootq);
    // }
    // rank[rootp] += rank[rootq];
    parent[rootq] = rootp;
    count--;
    return true;
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
};

class Solution {
private:
  struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {}
  };

public:
  // compute distance of each points
  int distance(vector<int> a, vector<int> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    UnionFind *uf = new UnionFind;
    uf->UF(n);
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edges.emplace_back(distance(points[i], points[j]), i, j);
      }
    }

    // sort by length
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) -> int { return a.len < b.len; });

    int ret = 0, num = 1;
    for (int i = 0; i < (int)edges.size(); i++) {
      // if edge(x, y) connect two different block,
      // this edge is useful.
      if (uf->_union(edges[i].x, edges[i].y)) {
        ret += edges[i].len;
        num++;
        if (num == n) {
          break;
        }
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) { return 0; }
