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
  int res = 0;

public:
  int postorder(TreeNode *root) {
    if (!root) {
      return 0;
    }

    int left = postorder(root->left);
    int right = postorder(root->right);
    this->res += abs(left - right);
    return left + right + root->val;
  }
  int findTilt(TreeNode *root) {
    postorder(root);
    return this->res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  TreeNode *root = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2, NULL, NULL);
  TreeNode *n2 = new TreeNode(3, NULL, NULL);
  root->left = n1;
  root->right = n2;

  Solution *s = new Solution;
  s->findTilt(root);
  return 0;
}
