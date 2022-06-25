#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int n = arr.size();
    int left = 0, right = n - 1;
    int absl, absr;
    while (right - left >= k) {
      absl = x - arr[left];
      absr = arr[right] - x;
      if (absl < absr || (absl == absr && left < right)) {
        right--;
      } else {
        left++;
      }
    }

    vector<int> res;
    for (int i = left; i <= right; i++) {
      res.push_back(arr[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
