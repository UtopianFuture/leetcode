#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
  vector<vector<int>> res;
  int end = 0;

public:
  void dfs(vector<vector<int>> graph, int n, vector<int> path) {
    if ((int)path.size() == 0) {
      path.push_back(0);
    }
    if (path.back() == end) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < (int)graph[n].size(); i++) {
      path.push_back(graph[n][i]);
      dfs(graph, graph[n][i], path);
      path.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> path;
    end = (int)graph.size() - 1;
    dfs(graph, 0, path);
    return res;
  }
};

class Solution1 {
private:
  vector<vector<int>> graph;
  vector<vector<int>> res;
  int end;

public:
  void backtrace(int cur, vector<int> tmp, int n) {
    if (tmp.size() == 0) {
      tmp.push_back(cur);
    }
    if ((int)tmp.back() == n) {
      this->res.push_back(tmp);
      return;
    }

    for (int i = 0; i < (int)graph[cur].size(); i++) {
      tmp.push_back(graph[cur][i]);
      backtrace(graph[cur][i], tmp, n);
      tmp.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    this->graph = graph;
    this->end = graph.size() - 1;
    vector<int> tmp;
    backtrace(0, tmp, this->end);
    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  Solution1 *s = new Solution1;
  vector<vector<int>> res = s->allPathsSourceTarget(graph);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
