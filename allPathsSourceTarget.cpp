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

int main(int argc, char *argv[]) {
  REOPEN_READ;
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  Solution *s = new Solution;
  vector<vector<int>> res = s->allPathsSourceTarget(graph);
  for (int i = 0; i < (int)res.size(); i++) {
    for (int j = 0; j < (int)res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
