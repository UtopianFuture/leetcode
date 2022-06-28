#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<int> res;
    int x = INT_MAX;
    int level = 0, tmp;
    vector<int> visited(n, 0);
    vector<vector<int>> graph(n);
    int m = edges.size();
    for (int i = 0; i < m; i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
    }

    queue<int> q;
    int size;
    for (int i = 0; i < n; i++) {
      q.push(i);
      visited[i] = 1;
      while (!q.empty()) {
        size = q.size();
        for (int k = 0; k < size; k++) {
          tmp = q.front();
          q.pop();
          for (int j = 0; j < (int)graph[tmp].size(); j++) {
            if (visited[graph[tmp][j]] == 0) {
              visited[graph[tmp][j]] = 1;
              q.push(graph[tmp][j]);
            }
          }
        }
        level++;
      }

      if (level < x) {
        x = level;
        res.clear();
        res.push_back(i);
      } else if (level == x) {
        res.push_back(i);
      }
      level = 0;
      visited.clear();
      visited.resize(n, 0);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> edges;
  int tmp1, tmp2;
  for (int i = 0; i < m; i++) {
    cin >> tmp1 >> tmp2;
    edges.push_back({tmp1, tmp2});
  }

  Solution *s = new Solution;
  vector<int> res = s->findMinHeightTrees(n, edges);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
