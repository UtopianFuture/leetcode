#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> map;
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
      map[nums[i]]++;
    }

    struct compare {
      bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second; // the less element is in top
      }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (auto m : map) {
      pq.push(m);
      if ((int)pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      res.push_back(pq.top().first);
      pq.pop();
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
