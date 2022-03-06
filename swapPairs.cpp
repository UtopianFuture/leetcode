#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *a, ListNode *b) {
    ListNode *pre, *cur, *next;
    cur = a;
    pre = NULL;
    while (cur != b) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    return pre;
  }

  ListNode *swapPairs(ListNode *head) {
    ListNode *end = head, *start = head;
    int count = 0;
    int k = 2;
    while (end != NULL && count < k) {
      end = end->next;
      count++;
    }
    if (count < k) {
      return head;
    }
    ListNode *newhead = reverse(head, end);
    start->next = swapPairs(end);
    return newhead;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  ListNode *head = new (ListNode);
  ListNode *p = head;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cin >> head->val;
    } else {
      ListNode *tmp = new (ListNode);
      cin >> tmp->val;
      p->next = tmp;
      p = p->next;
    }
  }

  Solution *s = new (Solution);
  ListNode *res = s->swapPairs(head);
  for (int i = 0; i < n; i++) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << "\n";

  return 0;
}
