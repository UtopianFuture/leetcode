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
  bool isContain(TreeNode *root) {
    if (!root) {
      return false;
    }
    bool left = isContain(root->left);
    bool right = isContain(root->right);
    if (!left) {
      root->left = NULL;
    }
    if (!right) {
      root->right = NULL;
    }
    return (root->val == 1) || left || right;
  }

  TreeNode *pruneTree(TreeNode *root) { return isContain(root) ? root : NULL; }
};

int main(int argc, char *argv[]) { return 0; }
