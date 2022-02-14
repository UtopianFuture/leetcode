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

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  } else if (q == NULL || p == NULL) {
    return false;
  } else if (q->val != p->val) {
    return false;
  } else {
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
}

int main() {
  int size1 = 0, size2 = 0;
  scanf("%d\n", &size1);

  int preorder1[size1], inorder1[size1];
  for (int i = 0; i < size1; i++) {
    scanf("%d", &preorder1[i]);
  }
  for (int i = 0; i < size1; i++) {
    scanf("%d", &inorder1[i]);
  }

  scanf("%d\n", &size2);

  int preorder2[size2], inorder2[size2];
  for (int i = 0; i < size2; i++) {
    scanf("%d", &preorder2[i]);
  }
  for (int i = 0; i < size2; i++) {
    scanf("%d", &inorder2[i]);
  }

  struct TreeNode *tree1 = buildTree(preorder1, size1, inorder1, size1);
  struct TreeNode *tree2 = buildTree(preorder2, size2, inorder2, size2);
  if (isSameTree(tree1, tree2)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}
