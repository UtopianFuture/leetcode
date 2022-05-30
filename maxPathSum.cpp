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
  int res = INT_MIN;

public:
  int calculate(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left = max(calculate(root->left), 0);
    int right = max(calculate(root->right), 0);
    res = max(left + right + root->val, res);
    return max(left, right) + root->val;
  }
  int maxPathSum(TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
      return root->val;
    }
    calculate(root);
    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;

  TreeNode *root = new TreeNode(2);
  TreeNode *n1 = new TreeNode(-1, NULL, NULL);
  // TreeNode *n2 = new TreeNode(20);
  // TreeNode *n3 = new TreeNode(15, NULL, NULL);
  // TreeNode *n4 = new TreeNode(7, NULL, NULL);
  root->left = NULL;
  root->right = n1;
  // n2->left = n3;
  // n2->right = n4;

  Solution *s = new Solution;
  cout << s->maxPathSum(root) << endl;

  return 0;
}
