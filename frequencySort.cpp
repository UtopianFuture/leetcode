#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  struct cmp {
    bool operator()(pair<char, int> p1, pair<char, int> p2) {
      return p1.second < p2.second;
    }
  };

  string frequencySort(string s) {
    unordered_map<char, int> map(26);
    int n = s.size();
    for (int i = 0; i < n; i++) {
      map[s[i]]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
    for (auto m : map) {
      pq.push(m);
    }

    string res;
    while (!pq.empty()) {
      int times = pq.top().second;
      char c = pq.top().first;
      for (int i = 0; i < times; i++) {
        res.push_back(c);
      }
      pq.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
