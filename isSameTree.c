#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

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

int main() { return 0; }
