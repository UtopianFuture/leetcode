#include "stdio.h"
#include "stdlib.h"
#include "tree.h"

struct status {
  int do_rob;
  int dont_rob;
};

struct status dp(struct TreeNode *node) {
  if (node == NULL) {
    return (struct status){0, 0};
  }

  struct status left = dp(node->left);
  struct status right = dp(node->right);
  int do_rob = node->val + left.dont_rob + right.dont_rob;
  int dont_rob =
      (left.do_rob > left.dont_rob ? left.do_rob : left.dont_rob) +
      (right.do_rob > right.dont_rob ? right.do_rob : right.dont_rob);

  return (struct status){do_rob, dont_rob};
}

int rob(struct TreeNode *root) {
  struct status s = dp(root);
  return s.do_rob > s.dont_rob ? s.do_rob : s.dont_rob;
}

// out time limits
// int rob(struct TreeNode *root) {
//   if (root == NULL)
//     return 0;
//
//   // rob root node
//   int do_rob = root->val +
//       (root->left == NULL ? 0
//            : (rob(root->left->left) + rob(root->left->right))) +
//       (root->right == NULL ? 0
//            : (rob(root->right->left) + rob(root->right->right)));
//
//   // don't rob root node
//   int dont_rob = rob(root->left) + rob(root->right);
//
//   return do_rob > dont_rob ? do_rob : dont_rob;
// }

int main() {
  int numsSize = 0;
  scanf("%d\n", &numsSize);

  int *nums = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  // printf("%d\n", rob(nums, numsSize));
  return 0;
}
