#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

class Solution {
public:
  bool isMatch(vector<int> a, vector<int> b) {
    return (a[0] < b[0] && a[1] < b[1]) || (a[0] > b[0] && a[1] > b[1]);
  }

  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int size = (int)envelopes.size();
    int val1 = 0, val2 = 0, max = 0;
    int *dp = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
      dp[i] = 1;
    }

    // sort(envelopes.begin(), envelopes.end(), cmp);
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (isMatch(envelopes[i], envelopes[j])) {
          val1 = dp[j] + 1;
        }
        val2 = val2 > val1 ? val2 : val1;
      }
      dp[i] = dp[i] > val2 ? dp[i] : val2;
      val1 = 0;
      val2 = 0;
      max = max > dp[i] ? max : dp[i];
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  vector<vector<int>> envelopes;
  int tmp1, tmp2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp1 >> tmp2;
    envelopes.push_back({tmp1, tmp2});
  }

  Solution *s = new (Solution);
  int res = s->maxEnvelopes(envelopes);
  cout << res << "\n";

  return 0;
}
