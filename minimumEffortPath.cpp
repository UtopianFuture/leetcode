#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
private:
  int row, col;

public:
  struct cmp {
    bool operator()(vector<int> na, vector<int> nb) { return na[2] > nb[2]; }
  };

  bool inArea(int x, int y) { return x >= 0 && x < row && y >= 0 && y < col; }

  int dijkstra(vector<vector<int>> heights) {
    vector<vector<int>> heightTo(row, vector<int>(col, INT_MAX));
    heightTo[0][0] = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    pq.push({0, 0, 0}); // x, y, height between current node and perview node.
    int curNodex, curNodey, curNodeToPrev;
    vector<int> tmp;
    while (!pq.empty()) {
      tmp = pq.top();
      pq.pop();

      curNodex = tmp[0];
      curNodey = tmp[1];
      curNodeToPrev = tmp[2];
      if (curNodeToPrev > heightTo[tmp[0]][tmp[1]]) {
        continue;
      }

      if (inArea(curNodex - 1, curNodey)) {
        int nextNodex = curNodex - 1;
        int nextNodey = curNodey;
        int heightBetween =
            abs(heights[nextNodex][nextNodey] - heights[curNodex][curNodey]);
        heightBetween = max(heightBetween, heightTo[curNodex][curNodey]);
        if (heightBetween < heightTo[nextNodex][nextNodey]) {
          heightTo[nextNodex][nextNodey] = heightBetween;
          pq.push({nextNodex, nextNodey, heightBetween});
        }
      }
      if (inArea(curNodex + 1, curNodey)) {
        int nextNodex = curNodex + 1;
        int nextNodey = curNodey;
        int heightBetween =
            abs(heights[nextNodex][nextNodey] - heights[curNodex][curNodey]);
        heightBetween = max(heightBetween, heightTo[curNodex][curNodey]);
        if (heightBetween < heightTo[nextNodex][nextNodey]) {
          heightTo[nextNodex][nextNodey] = heightBetween;
          pq.push({nextNodex, nextNodey, heightBetween});
        }
      }
      if (inArea(curNodex, curNodey - 1)) {
        int nextNodex = curNodex;
        int nextNodey = curNodey - 1;
        int heightBetween =
            abs(heights[nextNodex][nextNodey] - heights[curNodex][curNodey]);
        heightBetween = max(heightBetween, heightTo[curNodex][curNodey]);
        if (heightBetween < heightTo[nextNodex][nextNodey]) {
          heightTo[nextNodex][nextNodey] = heightBetween;
          pq.push({nextNodex, nextNodey, heightBetween});
        }
      }
      if (inArea(curNodex, curNodey + 1)) {
        int nextNodex = curNodex;
        int nextNodey = curNodey + 1;
        int heightBetween =
            abs(heights[nextNodex][nextNodey] - heights[curNodex][curNodey]);
        heightBetween = max(heightBetween, heightTo[curNodex][curNodey]);
        if (heightBetween < heightTo[nextNodex][nextNodey]) {
          heightTo[nextNodex][nextNodey] = heightBetween;
          pq.push({nextNodex, nextNodey, heightBetween});
        }
      }
    }
    return heightTo[row - 1][col - 1];
  }

  int minimumEffortPath(vector<vector<int>> &heights) {
    this->row = (int)heights.size();
    this->col = (int)heights[0].size();
    return dijkstra(heights);
  }
};

int main(int argc, char *argv[]) { return 0; }
