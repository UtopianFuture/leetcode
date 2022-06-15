#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = (int)nums.size();
    vector<int> res;
    deque<int> dq;
    int left = 0, right = 0;
    for (; right < k; right++) {
      while (!dq.empty() && nums[right] > dq.front()) {
        dq.pop_front();
      }
      dq.push_front(nums[right]);
    }

    res.push_back(dq.back());

    for (; right < n; right++) {
      while (!dq.empty() && nums[right] > dq.front()) {
        dq.pop_front();
      }
      dq.push_front(nums[right]);
      if (nums[left] == dq.back()) {
        dq.pop_back();
      }
      left++;
      res.push_back(dq.back());
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, k;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cin >> k;

  Solution *s = new Solution;
  vector<int> res = s->maxSlidingWindow(nums, k);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
