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
  bool isSame(TreeNode *a, TreeNode *b) {
    if (a == NULL && b == NULL) {
      return true;
    }
    if (a == NULL || b == NULL) {
      return false;
    }
    if (a->val != b->val) {
      return false;
    }
    return isSame(a->left, b->left) && isSame(a->right, b->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (!root) {
      return subRoot == NULL;
    }

    if (isSame(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

int main(int argc, char *argv[]) { return 0; }
