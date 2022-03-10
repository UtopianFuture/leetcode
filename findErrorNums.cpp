#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> res;
    int n = (int)nums.size();
    int tmp1;
    for (int i = 0; i < n; i++) {
      tmp1 = (nums[i] - 1) % n;
      if (nums[tmp1] > n) {
        res.push_back(tmp1 + 1);
      }
      nums[tmp1] += n;
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] <= n) {
        res.push_back(i + 1);
        break;
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
  vector<int> res = s->findErrorNums(nums);
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}
