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
  void invert(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    invert(root->left);
    invert(root->right);
    TreeNode *p;
    p = root->left;
    root->left = root->right;
    root->right = p;
    return;
  }

  TreeNode *invertTree(TreeNode *root) {
    invert(root);
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }
