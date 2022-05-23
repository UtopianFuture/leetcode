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
  bool mirror(TreeNode *a, TreeNode *b) {
    if (!a && !b) {
      return true;
    } else if (a == NULL && b) {
      return false;
    } else if (a && b == NULL) {
      return false;
    }
    if (a->val != b->val) {
      return false;
    }
    return mirror(a->left, b->right) && mirror(a->right, b->left);
  }

  bool isSymmetric(TreeNode *root) { return mirror(root, root); }
};

int main(int argc, char *argv[]) { return 0; }
