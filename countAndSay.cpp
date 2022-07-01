#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    } else if (n == 2) {
      return "11";
    }

    int count = 0;
    int target;
    vector<string> res(30);
    res[0] = "1";
    res[1] = "11";
    for (int i = 2; i < n; i++) {
      int n = (int)res[i - 1].size();
      for (int j = 0; j < n; j++) {
        target = res[i - 1][j];
        while (target == res[i - 1][j]) {
          count++;
          j++;
        }
        j--;
        res[i].push_back(count + '0');
        res[i].push_back(target);
        count = 0;
      }
    }
    return res[n - 1];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;

  Solution *s = new Solution;
  cout << s->countAndSay(n) << endl;
  return 0;
}
