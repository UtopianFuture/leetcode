#ifndef BUILDTREE_H_SY9M6IYJ
#define BUILDTREE_H_SY9M6IYJ

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.h"

struct TreeNode *build(int *preorder, int *inorder, int preorderSize,
                       int preorder_left, int preorder_right, int inorder_left,
                       int inorder_right);

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
                           int inorderSize);

#endif /* end of include guard: BUILDTREE_H_SY9M6IYJ */
