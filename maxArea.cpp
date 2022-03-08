#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = (int)height.size() - 1;
    int area = 0, maxarea = 0;
    while (i < j) {
      area = (j - i) * (min(height[i], height[j]));
      if (area > maxarea) {
        maxarea = area;
      }
      if (height[i] > height[j]) {
        j--;
      } else {
        i++;
      }
    }
    return maxarea;
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
  cout << s->maxArea(height) << "\n";

  return 0;
}
