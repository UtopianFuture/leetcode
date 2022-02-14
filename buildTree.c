#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct tagListNode {
  struct tagListNode *next;
  int val;
} ListNode;

typedef struct {
  ListNode *top;
} Stack;

Stack *Create() {
  Stack *stk = calloc(1, sizeof(Stack));
  return stk;
}

void Push(Stack *obj, int x) {
  ListNode *node = malloc(sizeof(ListNode));
  node->val = x;
  node->next = obj->top;
  obj->top = node;
}

int Pop(Stack *obj) {
  ListNode *node = obj->top;
  int val = node->val;
  obj->top = node->next;
  free(node);

  return val;
}

int Top(Stack *obj) { return obj->top->val; }

bool Empty(Stack *obj) { return (obj->top == NULL); }

void Free(Stack *obj) {
  while (obj->top != NULL) {
    ListNode *node = obj->top;
    obj->top = obj->top->next;
    free(node);
  }
  free(obj);
}

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
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
