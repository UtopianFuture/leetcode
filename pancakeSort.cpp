#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  void reverse(vector<int> &arr, int start, int end) {
    int tmp;
    while (start < end) {
      tmp = arr[end];
      arr[end] = arr[start];
      arr[start] = tmp;
      start++;
      end--;
    }
  }

  void sort(vector<int> &res, vector<int> &arr, int n) {
    if (n == 1) {
      return;
    }

    int maxindex = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > arr[maxindex]) {
        maxindex = i;
      }
    }

    // if max pancake is the last one,
    // don't sort this time
    if (maxindex != n - 1) {
      // if arr[0] is max, don't reverse
      if (maxindex != 0) {
        reverse(arr, 0, maxindex);
        res.push_back(maxindex + 1);
      }
      reverse(arr, 0, n - 1);
      res.push_back(n);
    }
    sort(res, arr, n - 1);
  }

  vector<int> pancakeSort(vector<int> &arr) {
    vector<int> res;
    sort(res, arr, (int)arr.size());
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> arr;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  Solution *s = new (Solution);
  vector<int> res = s->pancakeSort(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
