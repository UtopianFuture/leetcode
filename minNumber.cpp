#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool compare(const string &s1, const string &s2) {
    string ab = s1 + s2;
    string ba = s2 + s1;
    return ab < ba; // '303` is larger than '330`
  }
  string minNumber(vector<int> &nums) {
    int size = (int)nums.size();
    vector<string> tmp_s(size);
    string tmp, res;
    for (int i = 0; i < size; i++) {
      tmp = to_string(nums[i]);
      tmp_s[i] = tmp;
    }
    // sort is compare two elements, compare function is how to compare.
    sort(tmp_s.begin(), tmp_s.end(), compare);
    for (int i = 0; i < size; i++) {
      res += tmp_s[i];
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
  cout << s->minNumber(nums) << "\n";
  return 0;
}
