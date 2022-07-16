#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isVaild(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          visited[i][j] = 1;
        }
      }
    }

    int size = 0;
    int level = 1;
    while (!q.empty()) {
      size = q.size();
      for (int i = 0; i < size; i++) {
        pair<int, int> tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;

        if (isVaild(x - 1, y, n, m) && !visited[x - 1][y]) {
          dist[x - 1][y] = level;
          visited[x - 1][y] = 1;
          q.push({x - 1, y});
        }
        if (isVaild(x + 1, y, n, m) && !visited[x + 1][y]) {
          dist[x + 1][y] = level;
          visited[x + 1][y] = 1;
          q.push({x + 1, y});
        }
        if (isVaild(x, y - 1, n, m) && !visited[x][y - 1]) {
          dist[x][y - 1] = level;
          visited[x][y - 1] = 1;
          q.push({x, y - 1});
        }
        if (isVaild(x, y + 1, n, m) && !visited[x][y + 1]) {
          dist[x][y + 1] = level;
          visited[x][y + 1] = 1;
          q.push({x, y + 1});
        }
      }
      level++;
    }
    return dist;
  }
};

int main(int argc, char *argv[]) { return 0; }
