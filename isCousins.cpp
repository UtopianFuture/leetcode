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
  int x, y;
  TreeNode *parent_x;
  TreeNode *parent_y;
  int depth_x, depth_y;

public:
  void preorder(TreeNode *root, int depth, TreeNode *parent) {
    if (!root) {
      return;
    }
    if (root->val == this->x) {
      parent_x = parent;
      depth_x = depth;
    }
    if (root->val == this->y) {
      parent_y = parent;
      depth_y = depth;
    }
    preorder(root->left, depth + 1, root);
    preorder(root->right, depth + 1, root);
  }

  bool isCousins(TreeNode *root, int x, int y) {
    this->x = x;
    this->y = y;
    this->depth_x = 0;
    this->depth_y = 0;
    preorder(root, 0, NULL);
    if (depth_x == depth_y && parent_x != parent_y) {
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }
