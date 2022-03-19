#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class State {
public:
  int id;
  int distanceFromStart;

  State(int id, int distanceFromStart) {
    this->id = id;
    this->distanceFromStart = distanceFromStart;
  }
};

struct cmp {
  bool operator()(State *a, State *b) {
    return a->distanceFromStart > b->distanceFromStart;
  }
};

class Solution {
public:
  vector<int> dijkstra(int start, vector<vector<vector<int>>> &graph) {
    int size = graph.size();
    // disTo[i] is distance from start to point[i]
    vector<int> disTo(size, INT_MAX);
    disTo[start] = 0;
    priority_queue<State *, vector<State *>, cmp> pq;
    State *curState = new State(start, 0);
    pq.push(curState);

    int curStateId;
    int curDisFromState;
    while (!pq.empty()) {
      curState = pq.top();
      pq.pop();
      // current point id and
      // distance from start to it
      curStateId = curState->id;
      curDisFromState = curState->distanceFromStart;
      if (curDisFromState > disTo[curStateId]) {
        continue;
      }

      // traverse all adjacent points
      for (int i = 0; i < (int)graph[curStateId].size(); i++) {
        int nextStateId = graph[curStateId][i][0];
        // update the distance between next point and start
        int disToNextNode = disTo[curStateId] + graph[curStateId][i][1];
        // update the shortest path
        if (disTo[nextStateId] > disToNextNode) {
          disTo[nextStateId] = disToNextNode;
          State *nextState = new State(nextStateId, disToNextNode);
          pq.push(nextState);
        }
      }
    }
    return disTo;
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<vector<int>>> graph(n + 1);
    int size = (int)times.size();
    int from, to, weight;
    // build graph
    for (int i = 0; i < size; i++) {
      from = times[i][0];
      to = times[i][1];
      weight = times[i][2];
      graph[from].push_back({to, weight});
    }

    // find shortest path from start to all points
    vector<int> disTo = dijkstra(k, graph);
    int res = -1;
    // find the longest shortest path
    for (int i = 1; i < (int)disTo.size(); i++) {
      if (disTo[i] == INT_MAX) {
        return -1;
      }
      res = res > disTo[i] ? res : disTo[i];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  int n = 4, k = 2;
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  Solution *s = new Solution;
  cout << s->networkDelayTime(times, n, k);

  return 0;
}
