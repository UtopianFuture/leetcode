#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
  struct ListNode *res = malloc(sizeof(struct ListNode));
  struct ListNode *next;

  next = res;
  while (list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      next->next = list1;
      list1 = list1->next;
    } else {
      next->next = list2;
      list2 = list2->next;
    }
    next = next->next;
  }

  next->next = list1 == NULL ? list2 : list1;
  return res->next;
}

int main() {
  int size1 = 0, size2 = 0;

  scanf("%d\n", &size1);
  scanf("%d\n", &size2);

  struct ListNode *list1 = malloc(size1 * sizeof(int));
  struct ListNode *list2 = malloc(size2 * sizeof(int));

  for (int i = 0; i < size1; i++) {
    scanf("%d", &list1[i].val);
  }
  for (int i = 0; i < size2; i++) {
    scanf("%d", &list2[1].val);
  }

  struct ListNode *res = mergeTwoLists(list1, list2);
  for (int i = 0; i < size1 + size2; i++) {
    printf("%d", res[i].val);
    if (i == size1 + size2 - 1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }

  return 0;
}
