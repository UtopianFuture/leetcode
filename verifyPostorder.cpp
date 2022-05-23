#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Solution {
public:
  bool isPostOrder(vector<int> postorder, int start, int end) {
    if (start >= end) {
      return true;
    }

    int p = start;
    while (postorder[p] < postorder[end]) {
      p++;
    }
    int m = p;
    while (postorder[p] > postorder[end]) {
      p++;
    }

    return p == end && isPostOrder(postorder, start, m - 1) &&
           isPostOrder(postorder, m, end - 1);
  }

  bool verifyPostorder(vector<int> &postorder) {
    return isPostOrder(postorder, 0, postorder.size() - 1);
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  vector<int> postorder;
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    postorder.push_back(tmp);
  }

  Solution *s = new Solution;
  cout << (bool)s->verifyPostorder(postorder);

  return 0;
}
