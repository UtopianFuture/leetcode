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

struct TreeNode *build(int *preorder, int *inorder, int preorderSize,
                       int preorder_left, int preorder_right, int inorder_left,
                       int inorder_right) {
  if (preorder_left > preorder_right) {
    return NULL;
  }

  // the first node in preorder is root node
  int preorder_root = preorder_left;
  int inorder_root;
  for (int i = 0; i < preorderSize; i++) { // find root node in inorder
    if (inorder[i] == preorder[preorder_root]) {
      inorder_root = i;
      break;
    }
  }

  // build root node
  struct TreeNode *root = new (TreeNode);
  root->val = preorder[preorder_root];
  // left subtree size
  int size_left_subtree = inorder_root - inorder_left;
  // construct subtree and connect to root node
  root->left =
      build(preorder, inorder, preorderSize, preorder_left + 1,
            preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
  root->right = build(preorder, inorder, preorderSize,
                      preorder_left + size_left_subtree + 1, preorder_right,
                      inorder_root + 1, inorder_right);
  return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
                           int inorderSize) {
  return build(preorder, inorder, preorderSize, 0, preorderSize - 1, 0,
               preorderSize - 1);
}

void test(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  test(root->left);
  test(root->right);
}

class Solution {
private:
  stack<TreeNode *> s;

public:
  void flatten(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    if (root->right != NULL) {
      s.push(root->right);
    }
    root->right = root->left;
    root->left = NULL;
    if (root->right != NULL) {
      flatten(root->right);
    } else {
      if (!s.empty()) {
        root->right = s.top();
        s.pop();
        flatten(root->right);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  int *preorder = new int[n];
  int *inorder = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> preorder[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> inorder[i];
  }

  struct TreeNode *root = buildTree(preorder, n, inorder, n);
  Solution *s = new (Solution);
  s->flatten(root);
  test(root);
  return 0;
}
