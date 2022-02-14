#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

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

int successor(struct TreeNode *root) {
  root = root->right;
  while (root->left != NULL)
    root = root->left;
  return root->val;
}

int predecessor(struct TreeNode *root) {
  root = root->left;
  while (root->right != NULL)
    root = root->right;
  return root->val;
}

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
  if (root == NULL) {
    return NULL;
  }
  if (root->val > key) { // go to left
    root->left = deleteNode(root->left, key);
  } else if (root->val < key) { // go to right
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL && root->right == NULL) {
      return NULL;                    // this node is leaf node, delete directly
    } else if (root->right != NULL) { // this node has right node, use successor
      root->val = successor(root);
      root->right = deleteNode(root->right, root->val);
    } else { // this node don't have right, but has left node
      root->val = predecessor(root);
      root->left = deleteNode(root->left, root->val);
    }
  }
  return root;
}

int main() {
  //   int size = 0;
  //   scanf("%d\n", &size);
  //
  //   int preorder[size], inorder[size];
  //   for (int i = 0; i < size; i++) {
  //     scanf("%d", &preorder[i]);
  //   }
  //   for (int i = 0; i < size; i++) {
  //     scanf("%d", &inorder[i]);
  //   }

  int preorder[6] = {5, 3, 4, 7, 6, 8};
  int inorder[6] = {3, 4, 5, 6, 7, 8};
  struct TreeNode *n = buildTree(preorder, 6, inorder, 6);
  deleteNode(n, 5);
  return 0;
}
