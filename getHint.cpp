#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  string getHint(string secret, string guess) {
    string res;
    int n = secret.size();
    vector<int> nums1(10, 0);
    vector<int> nums2(10, 0);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (secret[i] == guess[i]) {
        x++;
      } else {
        nums1[secret[i] - '0']++;
        nums2[guess[i] - '0']++;
      }
    }

    for (int i = 0; i < 10; i++) {
      y += min(nums1[i], nums2[i]);
    }
    res += to_string(x) + "A" + to_string(y) + "B";
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  string secret, guess;
  cin >> secret >> guess;

  Solution *s = new Solution;
  cout << s->getHint(secret, guess) << endl;
  return 0;
}
