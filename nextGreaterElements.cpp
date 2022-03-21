#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int size = (int)nums.size();
    stack<int> s;
    vector<int> res(size, 0);
    int tmp;
    for (int i = 2 * size - 1; i >= 0; i--) {
      tmp = i % size;
      while (!s.empty() && s.top() <= nums[tmp]) {
        s.pop();
      }
      res[tmp] = s.empty() ? -1 : s.top();
      s.push(nums[tmp]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  Solution *s = new Solution;
  vector<int> res = s->nextGreaterElements(nums);
  for (int i = 0; i < n; i++) {
    cout << res[i] << "\n";
  }
  return 0;
}
