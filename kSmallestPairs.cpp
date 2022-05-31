#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    vector<vector<int>> res;
    auto compare = [&nums1, &nums2](const pair<int, int> &a,
                                    const pair<int, int> &b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second]; // the less element is in top
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);
    int n1 = (int)nums1.size();
    int n2 = (int)nums2.size();
    for (int i = 0; i < min(k, n1); i++) {
      pq.push({i, 0});
    }

    while (k-- > 0 && !pq.empty()) {
      auto tmp = pq.top();
      res.push_back({nums1[tmp.first], nums2[tmp.second]});
      pq.pop();
      if (tmp.second + 1 < n2) {
        pq.push({tmp.first, tmp.second + 1});
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
