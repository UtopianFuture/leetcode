#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  int arrayNesting(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> map;
    int start = 0;
    int size = 0, res = 0;
    for (int i = 0; i < n; i++) {
      start = nums[i];
      while (map[start] != 1) {
        map[start] = 1;
        size++;
        start = nums[start];
      }
      res = max(res, size);
      map.clear();
      size = 0;
    }
    return res;
  }
};

class Solution1 {
public:
  int arrayNesting(vector<int> &nums) {
    int n = nums.size();
    vector<int> visited(n, 0);
    int res = 0, size = 0;
    int start;
    for (int i = 0; i < n; i++) {
      start = nums[i];
      while (!visited[start]) {
        size++;
        visited[start] = 1;
        start = nums[start];
      }
      res = max(res, size);
      size = 0;
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
