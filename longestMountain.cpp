#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> calculate(vector<int> arr, int location) {
    int p = location;
    int left = p - 1;
    int right = p + 1;
    int n = 1;
    while (left >= 0 && arr[left] < arr[p]) {
      n++;
      left--;
      p--;
    }
    p = location;
    while (right < arr.size() && arr[right] < arr[p]) {
      n++;
      right++;
      p++;
    }
    return vector<int>{n, right};
  }

  int longestMountain(vector<int> &arr) {
    int n = arr.size();
    if (n < 3) {
      return 0;
    }
    int res = 0;

    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
        vector<int> tmp = calculate(arr, i);
        res = max(tmp[0], res);
        i = tmp[1] - 1;
      }
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
  cout << s->longestMountain(nums) << endl;

  return 0;
}
