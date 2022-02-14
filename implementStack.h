#ifndef IMPLEMENTSTACK_H_LR9UGF7H
#define IMPLEMENTSTACK_H_LR9UGF7H

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

Stack *Create();
void Push(Stack *obj, int x);
int Pop(Stack *obj);
int Top(Stack *obj);
bool Empty(Stack *obj);
void Free(Stack *obj);

#endif /* end of include guard: IMPLEMENTSTACK_H_LR9UGF7H */
