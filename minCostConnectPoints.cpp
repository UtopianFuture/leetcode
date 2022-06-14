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
      parent[x] = parent[parent[x]];
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
  int distance(vector<int> na, vector<int> nb) {
    return abs(na[0] - nb[0]) + abs(na[1] - nb[1]);
  }

  // static bool cmp(const vector<int> na, const vector<int> nb) {
  // return na[0] < nb[0];
  // }

  struct cmp {
    bool operator()(vector<int> na, vector<int> nb) { return na[0] > nb[0]; }
  };

  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = (int)points.size();
    int res = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> edge;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edge.push({distance(points[i], points[j]), i, j});
      }
    }

    // sort(edge.begin(), edge.end(), cmp);
    UnionFind *uf = new UnionFind;
    uf->UF(n);
    vector<int> tmp;
    // for (int i = 0; i < (int)edge.size(); i++) {
    while (!edge.empty()) {
      tmp = edge.top();
      edge.pop();
      if (!uf->connected(tmp[1], tmp[2])) {
        uf->_union(tmp[1], tmp[2]);
        res += tmp[0];
        n--;
        if (n == 0) {
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
