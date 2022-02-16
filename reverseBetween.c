#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
  if (left == right) {
    return head;
  }

  int location = 1;
  // add a sentinel node
  struct ListNode *res = malloc(sizeof(struct ListNode));
  res->next = head;
  // tmp head and tail is for reverse
  struct ListNode *tmp_head = malloc(sizeof(struct ListNode));
  // tmp tail recode the last node of the reverse list
  struct ListNode *tmp_tail;
  // this two nodes record the start location and end location
  struct ListNode *start_location, *end_location;
  struct ListNode *prev = res;
  while (head != NULL) {
    // recode the location before left node
    if (location == left) {
      start_location = prev;
      tmp_tail = head;
    }
    // recode the location before right node
    if (location == right) {
      end_location = head->next;
    }
    if (location >= left && location <= right) {
      head = head->next;
      prev->next->next = tmp_head->next;
      tmp_head->next = prev->next;
      prev->next = head;
    } else {
      prev = head;
      head = head->next;
    }
    location++;
  }

  start_location->next = tmp_head->next;
  tmp_tail->next = end_location;

  return res->next;
}

int main() {
  int n = 0;
  scanf("%d", &n);

  struct ListNode *head = malloc(n * sizeof(struct ListNode));
  for (int i = 0; i < n; i++) {
    scanf("%d", &head[i].val);
    if (i != n - 1) {
      head[i].next = &(head[i + 1]);
    } else {
      head[i].next = NULL;
    }
  }

  int start, end;
  scanf("%d", &start);
  scanf("%d", &end);
  struct ListNode *res = reverseBetween(head, start, end);
  while (res != NULL) {
    printf("%d ", res->val);
    res = res->next;
  }

  return 0;
}
