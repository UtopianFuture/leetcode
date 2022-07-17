#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = 0;
        }
        res = max(res, dp[i][j]);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, m;
  cin >> n >> m;
  vector<int> nums1(n);
  vector<int> nums2(m);
  for (int i = 0; i < n; i++) {
    cin >> nums1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> nums2[i];
  }

  Solution *s = new Solution;
  cout << s->findLength(nums1, nums2) << endl;
  return 0;
}
