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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  if (listsSize == 0) {
    return NULL;
  }
  if (listsSize == 1) {
    return lists[0];
  }

  int k = 0;
  struct ListNode **res;
  if (listsSize % 2 == 1) {
    res = malloc((listsSize / 2 + 1) * sizeof(struct ListNode *));
    res[k++] = lists[listsSize - 1];
    for (int i = 0; i < listsSize - 1; i += 2) {
      res[k++] = mergeTwoLists(lists[i], lists[i + 1]);
    }
  } else {
    res = malloc((listsSize / 2) * sizeof(struct ListNode *));
    for (int i = 0; i < listsSize; i += 2) {
      res[k++] = mergeTwoLists(lists[i], lists[i + 1]);
    }
  }

  return mergeKLists(res, k);
}

int main() {
  int k = 0;

  scanf("%d\n", &k);
  int *size = malloc(k * sizeof(int));
  for (int i = 0; i < k; i++) {
    scanf("%d", &size[i]);
  }

  struct ListNode **lists = malloc(k * sizeof(struct ListNode *));

  int sum = 0;
  for (int i = 0; i < k; i++) {
    lists[i] = malloc(size[i] * sizeof(struct ListNode));
    sum += size[i];
    for (int j = 0; j < size[i]; j++) {
      scanf("%d", &lists[i][j].val);
      if (j != size[i] - 1) {
        lists[i][j].next = &(lists[i][j + 1]);
      } else {
        lists[i][j].next = NULL;
      }
    }
  }

  struct ListNode *res = mergeKLists(lists, k);
  while (res != NULL) {
    printf("%d ", res->val);
    res = res->next;
  }

  return 0;
}
