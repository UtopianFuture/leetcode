#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    int res = 0;
    string target = "123450";
    vector<vector<int>> neighbor = {{1, 3}, {0, 2, 4}, {1, 5},
                                    {0, 4}, {1, 3, 5}, {2, 4}};

    string init;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        init.push_back(board[i][j] + '0');
      }
    }

    queue<pair<string, int>> q;
    unordered_map<string, int> map;
    map[init] = 1;
    q.push({init, res});
    pair<string, int> tmp;
    int n;
    while (!q.empty()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        tmp = q.front();
        q.pop();
        if (tmp.first == target) {
          return tmp.second;
        }

        int location = tmp.first.find('0');
        for (int j = 0; j < (int)neighbor[location].size(); j++) {
          swap(tmp.first[location], tmp.first[neighbor[location][j]]);
          string str = tmp.first;
          if (map[tmp.first] != 1) {
            q.push({str, res + 1});
            map[str] = 1;
          }
          swap(tmp.first[location], tmp.first[neighbor[location][j]]);
        }
      }
      res++;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  vector<vector<int>> board(2, vector<int>(3, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> board[i][j];
    }
  }

  Solution *s = new Solution;
  cout << s->slidingPuzzle(board) << endl;
  return 0;
}
