#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<TreeNode *> generate(int left, int right) {
    if (left > right) {
      return {NULL};
    }

    vector<TreeNode *> res;
    for (int i = left; i <= right; i++) {
      vector<TreeNode *> lchild = generate(left, i - 1);
      vector<TreeNode *> rchild = generate(i + 1, right);

      for (auto l : lchild) {
        for (auto r : rchild) {
          TreeNode *root = new TreeNode(i, l, r);
          res.push_back(root);
        }
      }
    }

    return res;
  }

  vector<TreeNode *> generateTrees(int n) { return generate(1, n); }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Solution *s = new Solution;
  s->generateTrees(n);
  return 0;
}
