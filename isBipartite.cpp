#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<int> color; // 0 for null, 1 for red, 2 for green
  bool flag = true;

public:
  void dfs(int n, int n_color, vector<vector<int>> &graph) {
    for (int i = 0; i < (int)graph[n].size(); i++) {
      if (color[n] == 1) {
        if (color[graph[n][i]] != 0) {
          if (color[graph[n][i]] == color[n]) {
            flag = false;
            return;
          }
          continue;
        } else {
          color[graph[n][i]] = 2;
        }
      } else if (color[n] == 2) {
        if (color[graph[n][i]] != 0) {
          if (color[graph[n][i]] == color[n]) {
            flag = false;
            return;
          }
          continue;
        } else {
          color[graph[n][i]] = 1;
        }
      } else if (color[n] == 0) {
        if (n_color == 1) {
          color[n] = 2;
        } else {
          color[n] = 1;
        }
      }
      dfs(graph[n][i], color[n], graph);
    }
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = (int)graph.size();
    color.resize(n);
    color[0] = 1;
    for (int i = 0; i < n && flag; i++) {
      dfs(i, 1, graph);
    }
    return flag;
  }
};

class Solution1 {
private:
  vector<int> color;
  bool vaild = true;

public:
  void dfs(vector<vector<int>> graph, int n_color, int n) {
    for (int i = 0; i < (int)graph[n].size(); i++) {
      if (color[n] == 1) {
        if (color[graph[n][i]] != 0) {
          if (color[n] == color[graph[n][i]]) {
            vaild = false;
            return;
          }
          continue;
        } else {
          color[graph[n][i]] = 2;
        }
      } else if (color[n] == 2) {
        if (color[graph[n][i]] != 0) {
          if (color[n] == color[graph[n][i]]) {
            vaild = false;
            return;
          }
          continue;
        } else {
          color[graph[n][i]] = 1;
        }
      } else {
        if (n_color == 1) {
          color[graph[n][i]] = 2;
        } else {
          color[graph[n][i]] = 1;
        }
      }
      dfs(graph, color[n], graph[n][i]);
    }
  }

  bool isBipartite(vector<vector<int>> &graph) {
    int n = (int)graph.size();
    color.resize(n);
    color[0] = 1;
    for (int i = 0; i < n && vaild; i++) {
      dfs(graph, 1, i);
    }

    return vaild;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> graph = {{1}, {0}, {4}, {4}, {2, 3}};
  Solution *s = new Solution;
  cout << s->isBipartite(graph);
  return 0;
}
