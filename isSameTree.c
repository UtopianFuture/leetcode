#include "buildTree.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

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
