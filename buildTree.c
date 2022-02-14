#include "buildTree.h"

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
  struct TreeNode *root = malloc(sizeof(struct TreeNode));
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

int main() {
  int size = 0;
  scanf("%d\n", &size);

  int preorder[size], inorder[size];
  for (int i = 0; i < size; i++) {
    scanf("%d", &preorder[i]);
  }
  for (int i = 0; i < size; i++) {
    scanf("%d", &inorder[i]);
  }

  buildTree(preorder, size, inorder, size);
  return 0;
}
