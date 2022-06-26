#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int dijkstra(vector<vector<int>> flights, int n, int src, int dst, int k) {
    int res = INT_MAX;
    vector<int> disTo(n, INT_MAX);
    disTo[src] = 0;
    queue<vector<int>> q;
    vector<vector<vector<int>>> graph(n);
    int from, to, dis;
    for (int i = 0; i < (int)flights.size(); i++) {
      from = flights[i][0];
      to = flights[i][1];
      dis = flights[i][2];
      graph[from].push_back({to, dis});
    }

    q.push({src, 0});
    int num = 0, level = 0;
    int curCity, curDisToSrc;
    vector<int> tmp;
    while (!q.empty()) {
      num = q.size();

      for (int i = 0; i < num; i++) {
        tmp = q.front();
        q.pop();
        curCity = tmp[0];
        curDisToSrc = tmp[1];

        if (curCity == dst && level <= k + 1) {
          res = min(res, curDisToSrc);
        }
        // if (curDisToSrc > disTo[curCity]) {
        // continue;
        // }

        for (int j = 0; j < (int)graph[curCity].size(); j++) {
          int nextCity = graph[curCity][j][0];
          int nextDisToSrc = graph[curCity][j][1] + disTo[curCity];
          if (nextDisToSrc < disTo[nextCity]) {
            disTo[nextCity] = nextDisToSrc;
            q.push({nextCity, nextDisToSrc});
          }
        }
      }
      level++;
    }
    if (res == INT_MAX) {
      return -1;
    }
    return res;
  }

  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    return dijkstra(flights, n, src, dst, k);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int num, n, src, dst, k;
  cin >> num >> n >> src >> dst >> k;
  vector<vector<int>> edges;
  int from, to, dis;
  for (int i = 0; i < num; i++) {
    cin >> from >> to >> dis;
    edges.push_back({from, to, dis});
  }

  Solution *s = new Solution;
  cout << s->findCheapestPrice(n, edges, src, dst, k);
  return 0;
}
