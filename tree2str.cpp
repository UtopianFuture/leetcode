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
  string tree2str(TreeNode *root) {
    if (!root) {
      return "";
    }
    if (root->left == NULL && root->right == NULL) {
      return to_string(root->val);
    }

    string left = tree2str(root->left);
    string right = tree2str(root->right);

    if (left != "" && right == "") {
      return to_string(root->val) + "(" + left + ")";
    }
    if (left == "" && right != "") {
      return to_string(root->val) + "()(" + right + ")";
    }

    return to_string(root->val) + "(" + left + ")" + "(" + right + ")";
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  TreeNode *root = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3, NULL, NULL);
  TreeNode *n3 = new TreeNode(4, NULL, NULL);
  root->left = n1;
  root->right = n2;
  n1->left = NULL;
  n1->right = n3;

  Solution *s = new Solution;
  cout << s->tree2str(root) << endl;

  return 0;
}
