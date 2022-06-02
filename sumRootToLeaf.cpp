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
  string order;
  int res = 0;

public:
  void calculate(string order) {
    int digit = 1;
    for (int i = (int)order.size() - 1; i >= 0; i--) {
      res += (order[i] - '0') * digit;
      digit *= 2;
    }
  }

  void preorder(TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
      order.push_back(root->val + '0');
      calculate(order);
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

  int sumRootToLeaf(TreeNode *root) {
    preorder(root);
    return res;
  }
};

int main(int argc, char *argv[]) { return 0; }
