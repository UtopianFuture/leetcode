#include "implementStack.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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

int *nextGreaterElement(int *nums1, int nums1Size, int *nums2, int nums2Size,
                        int *returnSize) {
  int *tmp = malloc(nums2Size * sizeof(int));
  Stack *s = Create();

  for (int i = 0; i < nums2Size; i++) {
    while (!Empty(s) && Top(s) < nums2[i]) {
      Pop(s);
    }
    tmp[i] = Empty(s) ? -1 : Top(s);
    Push(s, nums2[i]);
  }

  for (int i = 0; i < nums1Size; i++) {
    for (int j = 0; j < nums2Size; j++) {
      if (nums2[j] == nums1[i]) {
        returnSize[i] = tmp[j];
        break;
      }
    }
  }

  return returnSize;
}

int main() {
  int size1 = 0, size2 = 0;
  scanf("%d %d\n", &size1, &size2);

  int *nums1 = malloc(size1 * sizeof(int));
  int *nums2 = malloc(size2 * sizeof(int));

  for (int i = 0; i < size1; i++) {
    scanf("%d", &nums1[i]);
  }

  for (int i = 0; i < size2; i++) {
    scanf("%d", &nums2[i]);
  }

  int *res = malloc(size1 * sizeof(int));
  nextGreaterElement(nums1, size1, nums2, size2, res);
  for (int i = 0; i < size2; i++) {
    scanf("%d", &res[i]);
  }
}
