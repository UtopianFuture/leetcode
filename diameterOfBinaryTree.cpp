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
  int m = 0;

public:
  int height(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    m = max(leftheight + rightheight, m);
    return max(leftheight, rightheight) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    height(root);
    return m;
  }
};

int main(int argc, char *argv[]) { return 0; }
