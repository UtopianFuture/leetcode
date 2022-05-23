#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void mirror(TreeNode *root) {
    if (!root) {
      return;
    }
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
  }

  TreeNode *mirrorTree(TreeNode *root) {
    mirror(root);
    return root;
  }
};

int main(int argc, char *argv[]) { return 0; }
