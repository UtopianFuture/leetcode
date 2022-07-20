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

class Solution1 {
public:
  struct cmp {
    bool operator()(vector<int> na, vector<int> nb) { return na[1] > nb[1]; }
  };

  vector<int> dijkstra(vector<vector<vector<int>>> graph, int k) {
    int n = (int)graph.size();
    vector<int> disTo(n, INT_MAX); // distance from current node to start node.
    disTo[k] = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({k, 0}); // 'k' is start node,
                     //'0' is distance from current node to start node.
    vector<int> tmp;
    int curNode, curNodeToStart;
    while (!pq.empty()) {
      tmp = pq.top();
      pq.pop();

      curNode = tmp[0];
      curNodeToStart = tmp[1];
      if (disTo[curNode] < curNodeToStart) {
        continue;
      }

      for (int i = 0; i < (int)graph[curNode].size(); i++) {
        int nextNode = graph[curNode][i][0];
        int nextNodeToStart = graph[curNode][i][1] + disTo[curNode];
        if (nextNodeToStart < disTo[nextNode]) {
          disTo[nextNode] = nextNodeToStart;
          pq.push({nextNode, nextNodeToStart});
        }
      }
    }
    return disTo;
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<vector<int>>> graph(n + 1);
    int from, to, distance;
    for (int i = 0; i < (int)times.size(); i++) {
      from = times[i][0];
      to = times[i][1];
      distance = times[i][2];
      graph[from].push_back({to, distance});
    }

    vector<int> disTo = dijkstra(graph, k);
    int max = INT_MIN;
    for (int i = 1; i <= n; i++) {
      if (disTo[i] == INT_MAX) {
        return -1;
      }
      if (disTo[i] > max) {
        max = disTo[i];
      }
    }
    return max;
  }
};

class Solution2 {
public:
  struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
    }
  };

  vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>> graph) {
    vector<int> disTo(n + 1, INT_MAX);
    disTo[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});
    int curNode, curNodeToStart;
    pair<int, int> tmp;
    while (!pq.empty()) {
      tmp = pq.top();
      pq.pop();

      curNode = tmp.first;
      curNodeToStart = tmp.second;

      if (curNodeToStart > disTo[curNode]) {
        continue;
      }

      for (int i = 0; i < graph[curNode].size(); i++) {
        int nextNode = graph[curNode][i].first;
        int nextNodeToStart = graph[curNode][i].second + disTo[curNode];
        if (nextNodeToStart < disTo[nextNode]) {
          disTo[nextNode] = nextNodeToStart;
          pq.push({nextNode, nextNodeToStart});
        }
      }
    }
    return disTo;
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    graph[0].push_back({INT_MIN, INT_MIN});
    int from, to, dis;
    for (int i = 0; i < times.size(); i++) {
      from = times[i][0];
      to = times[i][1];
      dis = times[i][2];
      graph[from].push_back({to, dis});
    }

    int res = INT_MIN;
    vector<int> disTo = dijkstra(n, k, graph);
    for (int i = 1; i < disTo.size(); i++) {
      if (disTo[i] == INT_MAX) {
        res = -1;
        break;
      } else if (i != k && disTo[i] > res) {
        res = disTo[i];
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  int n = 4, k = 2;
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  Solution2 *s = new Solution2;
  cout << s->networkDelayTime(times, n, k);

  return 0;
}
