#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool sequenceReconstruction(vector<int> &nums,
                              vector<vector<int>> &sequences) {
    int n = nums.size();
    if (n < 2) {
      return nums == sequences[0];
    }
    vector<int> indegree(n + 1, 0);
    vector<unordered_set<int>> graph(n + 1);
    int from, to;
    for (int i = 0; i < sequences.size(); i++) {
      for (int j = 1; j < sequences[i].size(); j++) {
        from = sequences[i][j - 1];
        to = sequences[i][j];
        if (!graph[from].count(to)) {
          graph[from].emplace(to);
          indegree[to]++;
        }
      }
    }

    queue<int> q;
    for (int i = 0; i <= n; i++) {
      if (indegree[i] == 0 && graph[i].size() > 0) {
        q.push(i);
      }
    }

    vector<int> res;
    int cur;
    while (!q.empty()) {
      if (q.size() > 1) {
        return false;
      }

      cur = q.front();
      res.push_back(cur);
      q.pop();
      for (auto next : graph[cur]) {
        indegree[next]--;
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }
    return res == nums;
  }
};

int main(int argc, char *argv[]) { return 0; }
