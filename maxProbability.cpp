#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class State {
public:
  int id;
  double probabilityFromStart;

  State(int id, double probabilityFromStart) {
    this->id = id;
    this->probabilityFromStart = probabilityFromStart;
  }
};

struct cmp {
  bool operator()(State *a, State *b) {
    return a->probabilityFromStart < b->probabilityFromStart;
  }
};

class Solution {
public:
  vector<double> dijkstra(vector<vector<vector<double>>> &graph, int start,
                          int end, int n) {
    priority_queue<State *, vector<State *>, cmp> pq;
    State *curState = new State(start, 1.0);
    pq.push(curState);
    vector<double> probability(n, 0);
    probability[start] = 1;

    int curStateId;
    double curStateProbability = 0;
    while (!pq.empty()) {
      curState = pq.top();
      pq.pop();
      curStateId = curState->id;
      curStateProbability = curState->probabilityFromStart;

      if (curStateId == end) {
        return {1, curStateProbability};
      }
      for (int i = 0; i < (int)graph[curStateId].size(); i++) {
        int nextStateId = graph[curStateId][i][0];
        double nextStateProbability =
            graph[curStateId][i][1] * curStateProbability;
        if (nextStateProbability > probability[nextStateId]) {
          probability[nextStateId] = nextStateProbability;
          pq.push(new State(nextStateId, nextStateProbability));
        }
      }
    }
    return {0, curStateProbability};
  }

  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    vector<vector<vector<double>>> graph(n);
    int size = (int)edges.size();
    for (int i = 0; i < size; i++) {
      graph[edges[i][0]].push_back({(double)edges[i][1], succProb[i]});
      graph[edges[i][1]].push_back({(double)edges[i][0], succProb[i]});
    }

    vector<double> res = dijkstra(graph, start, end, n);
    if (res[0] == 0) {
      return 0;
    } else {
      return res[1];
    }
  }
};

class Solution1 {
public:
  struct cmp {
    bool operator()(vector<double> na, vector<double> nb) {
      return na[1] < nb[1];
    }
  };

  vector<double> dijkstra(int n, vector<vector<vector<double>>> graph,
                          int start) {
    vector<double> disTo(n, 0);
    disTo[start] = 1;
    priority_queue<vector<double>, vector<vector<double>>, cmp> pq;
    pq.push({(double)start, 1});
    double curNode, curNodeToStart;
    vector<double> tmp;
    while (!pq.empty()) {
      tmp = pq.top();
      pq.pop();

      curNode = tmp[0];
      curNodeToStart = tmp[1];
      if (curNodeToStart < disTo[curNode]) {
        continue;
      }
      for (int i = 0; i < (int)graph[curNode].size(); i++) {
        double nextNode = graph[curNode][i][0];
        double nextNodeToStart = disTo[curNode] * graph[curNode][i][1];
        if (nextNodeToStart > disTo[nextNode]) {
          disTo[nextNode] = nextNodeToStart;
          pq.push({nextNode, nextNodeToStart});
        }
      }
    }
    return disTo;
  }

  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    vector<vector<vector<double>>> graph(n);
    double from, to, prob;
    for (int i = 0; i < (int)edges.size(); i++) {
      from = edges[i][0];
      to = edges[i][1];
      prob = succProb[i];
      graph[from].push_back({to, prob});
      graph[to].push_back({from, prob});
    }

    vector<double> disTo = dijkstra(n, graph, start);
    return disTo[end];
  }
};

class Solution2 {
public:
  struct cmp {
    bool operator()(pair<int, double> a, pair<int, double> b) {
      return a.second < b.second;
    }
  };

  double dijkstra(vector<vector<pair<int, double>>> graph, int start, int end,
                  int n) {
    priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;
    vector<double> disTo(n, -1);
    disTo[start] = 1;
    pq.push({start, 1});
    pair<int, double> tmp;
    int curNode;
    double curNodeToStart;
    while (!pq.empty()) {
      tmp = pq.top();
      pq.pop();

      curNode = tmp.first;
      curNodeToStart = tmp.second;

      if (curNode == end) {
        return curNodeToStart;
      }

      if (disTo[curNode] > curNodeToStart) {
        continue;
      }

      for (int i = 0; i < graph[curNode].size(); i++) {
        int nextNode = graph[curNode][i].first;
        double nextNodeToStart = graph[curNode][i].second * disTo[curNode];
        if (nextNodeToStart > disTo[nextNode]) {
          disTo[nextNode] = nextNodeToStart;
          pq.push({nextNode, nextNodeToStart});
        }
      }
    }
    return 0.0;
  }

  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start, int end) {
    int size = edges.size();
    vector<vector<pair<int, double>>> graph(n);
    int from, to;
    for (int i = 0; i < size; i++) {
      from = edges[i][0];
      to = edges[i][1];
      graph[from].push_back({to, succProb[i]});
      graph[to].push_back({from, succProb[i]});
    }

    return dijkstra(graph, start, end, n);
  }
};

int main(int argc, char *argv[]) {
  int n = 3;
  int start = 0, end = 2;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<double> succProb = {0.5, 0.5, 0.2};
  Solution2 *s = new Solution2;
  cout << s->maxProbability(n, edges, succProb, start, end);

  return 0;
}
