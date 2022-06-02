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
private:
  int res = INT_MAX;
  TreeNode *pre = NULL;

public:
  void inorder(TreeNode *root) {
    if (!root) {
      return;
    }

    inorder(root->left);
    if (pre) {
      res = min(res, root->val - pre->val);
    }
    pre = root;
    inorder(root->right);
  }

  int minDiffInBST(TreeNode *root) {
    inorder(root);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
