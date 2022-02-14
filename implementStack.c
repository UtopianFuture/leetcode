#include "implementStack.h"

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

int main() {
  Stack *s = malloc(sizeof(Stack));
  Push(s, 1);
  Push(s, 2);
  Top(s);
  Pop(s);
  Empty(s);
  return 0;
}
