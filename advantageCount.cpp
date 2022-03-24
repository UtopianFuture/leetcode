#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    int n = (int)nums1.size();
    vector<vector<int>> clone(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      clone[i][0] = nums2[i];
      clone[i][1] = i;
    }

    sort(clone.begin(), clone.end(), greater<vector<int>>());
    sort(nums1.begin(), nums1.end(), less<int>());
    vector<int> res(n, 0);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
      if (nums1[right] > clone[i][0]) {
        res[clone[i][1]] = nums1[right];
        right--;
      } else {
        res[clone[i][1]] = nums1[left];
        left++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums1, nums2;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums1.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums2.push_back(tmp);
  }

  Solution *s = new Solution;
  vector<int> res = s->advantageCount(nums1, nums2);
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
