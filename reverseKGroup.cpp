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

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *end = head, *start = head;
    int count = 0;
    while (end != NULL && count < k) {
      end = end->next;
      count++;
    }
    if (count < k) {
      return head;
    }
    ListNode *newhead = reverse(head, end);
    start->next = reverseKGroup(end, k);
    return newhead;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, k;
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

  cin >> k;
  Solution *s = new (Solution);
  ListNode *res = s->reverseKGroup(head, k);
  for (int i = 0; i < n; i++) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << "\n";

  return 0;
}
