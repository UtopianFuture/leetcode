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
  vector<TreeNode *> order;

public:
  void postorder(TreeNode *root) {
    if (!root) {
      return;
    }
    postorder(root->left);
    order.push_back(root);
    postorder(root->right);
  }
  TreeNode *increasingBST(TreeNode *root) {
    postorder(root);
    for (int i = 0; i < (int)order.size() - 1; i++) {
      order[i]->right = order[i + 1];
      order[i]->left = NULL;
    }
    order[(int)order.size() - 1]->left = NULL;
    order[(int)order.size() - 1]->right = NULL;

    return order[0];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;

  TreeNode *root = new TreeNode(5);
  TreeNode *n1 = new TreeNode(1, NULL, NULL);
  TreeNode *n2 = new TreeNode(7, NULL, NULL);
  // TreeNode *n3 = new TreeNode(15, NULL, NULL);
  // TreeNode *n4 = new TreeNode(7, NULL, NULL);
  root->left = n1;
  root->right = n2;
  // n2->left = n3;
  // n2->right = n4;

  Solution *s = new Solution;
  s->increasingBST(root);

  return 0;
}
