#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    vector<int> res;
    sort(arr.begin(), arr.end(), less<int>());
    for (int i = 0; i < k; i++) {
      res.push_back(arr[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
