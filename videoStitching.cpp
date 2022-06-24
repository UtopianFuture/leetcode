#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  static bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) {
      return a[1] > b[1];
    }
    return a[0] < b[0];
  }

  int videoStitching(vector<vector<int>> &clips, int time) {
    int n = clips.size();
    sort(clips.begin(), clips.end(), cmp);
    if (clips[0][0] > 0) {
      return -1;
    }

    int start = clips[0][0];
    int end = clips[0][1];
    int next = 0, m = end;
    int res = 1;
    if (end >= time) {
      return res;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (clips[j][0] <= end && clips[j][1] > m) {
          next = j;
          m = clips[j][1];
        }
      }
      start = clips[next][0];
      end = clips[next][1];
      res++;
      if (end >= time) {
        return res;
      }
      if (next == i) {
        break;
      }
      i = next - 1;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, time;
  cin >> n >> time;
  vector<vector<int>> clips(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> clips[i][0] >> clips[i][1];
  }

  Solution *s = new Solution;
  cout << s->videoStitching(clips, time) << endl;
  return 0;
}
