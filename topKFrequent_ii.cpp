#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  struct cmp {
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
      if (a.second == b.second) {
        return a.first < b.first;
      } else {
        return a.second > b.second;
      }
    }
  };

  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> map;
    int n = words.size();
    for (int i = 0; i < n; i++) {
      map[words[i]]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (auto m : map) {
      pq.push(m);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<string> res;
    while (!pq.empty()) {
      res.insert(res.begin(), pq.top().first);
      pq.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
