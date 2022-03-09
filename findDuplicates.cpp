#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> res;
    int tmp;
    int n = (int)nums.size();
    int max = 2 * n;
    for (int i = 0; i < n; i++) {
      tmp = nums[i] - 1;
      nums[tmp % n] += n;
      if (nums[tmp % n] > max) {
        res.push_back(tmp % n + 1);
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  int tmp;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    nums.push_back(tmp);
  }

  Solution *s = new (Solution);
  vector<int> res = s->findDuplicates(nums);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
