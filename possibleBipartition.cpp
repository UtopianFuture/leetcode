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

  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    int size = (int)dislikes.size();
    color.resize(n + 1);
    color[1] = 1;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < size; i++) {
      // both directions should build connect
      graph[dislikes[i][0]].push_back(dislikes[i][1]);
      graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    for (int i = 1; i <= n && flag; i++) {
      dfs(i, 1, graph);
    }

    return flag;
  }
};

int main(int argc, char *argv[]) {
  int n = 5;
  vector<vector<int>> dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  Solution *s = new Solution;
  cout << s->possibleBipartition(n, dislikes);

  return 0;
}
