#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> edges;
  vector<int> visited;
  vector<int> topology;
  bool flag = 1;

public:
  void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < (int)edges[n].size(); i++) {
      if (visited[edges[n][i]] == 0) {
        dfs(edges[n][i]);
        if (flag == 0) {
          return;
        }
      } else if (visited[edges[n][i]] == 1) {
        flag = false;
        return;
      }
    }
    visited[n] = 2;
    topology.insert(topology.begin(), n);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    // topology.resize(numCourses);

    for (int i = 0; i < (int)prerequisites.size(); i++) {
      edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < numCourses && flag; i++) {
      if (visited[i] == 0) {
        dfs(i);
      }
    }
    if (flag == 0) {
      return {};
    }
    return topology;
  }
};

class Solution1 {
private:
  vector<vector<int>> edge;
  vector<int> visited;
  vector<int> res;
  bool vaild = true;
  int num;

public:
  void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < (int)edge[n].size(); i++) {
      if (visited[edge[n][i]] == 0) {
        dfs(edge[n][i]);
        if (!vaild) {
          res.pop_back();
          return;
        } else if (visited[edge[n][i]] == 1) {
          vaild = false;
          return;
        }
      }
    }
    visited[n] = 2;
    res.insert(res.begin(), n);
  }

  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    this->num = numCourses;
    edge.resize(numCourses);
    visited.resize(numCourses);
    for (int i = 0; i < (int)prerequisites.size(); i++) {
      edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses && vaild; i++) {
      if (visited[i] == 0) {
        dfs(i);
      }
    }
    return vaild ? res : vector<int>{-1, -1};
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  int numCourses = 4;
  Solution *s = new Solution;
  vector<int> res = s->findOrder(numCourses, prerequisites);
  for (int i = 0; i < numCourses; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
