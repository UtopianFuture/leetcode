#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int trap(vector<int> &height) {
    int res = 0;
    int left = 0, right = (int)height.size() - 1;
    int leftmax = 0, rightmax = 0;
    while (left < right) {
      leftmax = max(leftmax, height[left]);
      rightmax = max(rightmax, height[right]);
      if (height[left] < height[right]) {
        res += leftmax - height[left];
        left++;
      } else {
        res += rightmax - height[right];
        right--;
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
  vector<int> height;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    height.push_back(tmp);
  }

  Solution *s = new (Solution);
  cout << s->trap(height) << "\n";

  return 0;
}
