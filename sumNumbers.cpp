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
  long sum = 0;
  string order;

public:
  void preorder(TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
      order.push_back(root->val + '0');
      sum += stol(order);
      return;
    }
    order.push_back(root->val + '0');
    if (root->left) {
      preorder(root->left);
      order.pop_back();
    }
    if (root->right) {
      preorder(root->right);
      order.pop_back();
    }
  }
  int sumNumbers(TreeNode *root) {
    preorder(root);
    return sum;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;

  TreeNode *root = new TreeNode(0);
  TreeNode *n1 = new TreeNode(1);
  // TreeNode *n2 = new TreeNode(0, NULL, NULL);
  // TreeNode *n3 = new TreeNode(5, NULL, NULL);
  // TreeNode *n4 = new TreeNode(1, NULL, NULL);
  root->left = n1;
  // root->right = n2;
  // n1->left = n3;
  // n1->right = n4;

  Solution *s = new Solution;
  s->sumNumbers(root);
  return 0;
}
