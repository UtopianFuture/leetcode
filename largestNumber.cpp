#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(string s1, string s2) { return s1 + s2 > s2 + s1; }

  string largestNumber(vector<int> &nums) {
    int n = nums.size();
    vector<string> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[i] = to_string(nums[i]);
    }

    string res;
    sort(tmp.begin(), tmp.end(), cmp);
    if (tmp[0][0] == '0') {
      return "0";
    }
    for (int i = 0; i < n; i++) {
      res += tmp[i];
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution *s = new Solution;
  cout << s->largestNumber(nums) << endl;
  return 0;
}
