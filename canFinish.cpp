#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  vector<vector<int>> edges;
  vector<int> visited;
  bool valid = true;

public:
  void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < (int)edges[n].size(); i++) {
      // this node has not been visited
      if (visited[edges[n][i]] == 0) {
        dfs(edges[n][i]);
        if (!valid) {
          return;
        }
        // this node is visiting,
        // so there is a loop,
        // no topology order
      } else if (visited[edges[n][i]] == 1) {
        valid = false;
        return;
      }
    }
    visited[n] = 2;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // record each node's output
    edges.resize(numCourses);
    // record if each node has been visited
    visited.resize(numCourses);
    for (int i = 0; i < (int)prerequisites.size(); i++) {
      edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses && valid; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    return valid;
  }
};

class Solution1 {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<bool> isFinish(numCourses, 1);
    for (int i = 0; i < (int)prerequisites.size(); i++) {
      isFinish[prerequisites[i][0]] = 0;
    }

    bool flag = 0;
    for (int i = 0; i < (int)prerequisites.size(); i++) {
      flag = 0;
      for (int j = 1; j < (int)prerequisites[i].size(); j++) {
        if (isFinish[prerequisites[i][j]] == 0) {
          flag = 0;
          break;
        }
        flag = 1;
      }
      if (flag) {
        isFinish[prerequisites[i][0]] = 1;
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (isFinish[i] == 0) {
        return false;
      }
    }
    return true;
  }
};

class Solution2 {
private:
  vector<vector<int>> edge;
  vector<int> visited;
  bool res = true;

public:
  void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < (int)edge[n].size(); i++) {
      if (visited[edge[n][i]] == 0) {
        dfs(edge[n][i]);
        if (!res) {
          return;
        }
      } else if (visited[edge[n][i]] == 1) {
        res = false;
        return;
      }
    }
    visited[n] = 2;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    edge.resize(numCourses);
    visited.resize(numCourses, 0);
    for (int i = 0; i < (int)prerequisites.size(); i++) {
      edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses && res; i++) {
      if (visited[i] == 0) {
        dfs(i);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> prerequisites = {{2, 1}, {1, 0}};
  int numCourses = 3;
  Solution *s = new Solution;
  cout << s->canFinish(numCourses, prerequisites);
  return 0;
}
