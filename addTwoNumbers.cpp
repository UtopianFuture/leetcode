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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *res = new ListNode;
    ListNode *p = res;
    ListNode *pl1 = l1, *pl2 = l2;
    ListNode *next1, *next2;
    int sum = 0;
    int vl1 = 0, vl2 = 0, vp = 0;
    while (pl1 != NULL || pl2 != NULL) {
      if (pl1 != NULL) {
        vl1 = pl1->val;
        next1 = pl1->next;
      } else {
        next1 = NULL;
        vl1 = 0;
      }
      if (pl2 != NULL) {
        vl2 = pl2->val;
        next2 = pl2->next;
      } else {
        vl2 = 0;
        next2 = NULL;
      }
      vp = p->val;
      sum = vp + vl1 + vl2;
      p->val = sum % 10;
      // judge is this number is highest, and if it's 0
      // if it does, wo don't need it
      if (next1 != NULL || next2 != NULL || sum / 10 != 0) {
        ListNode *tmp = new ListNode;
        p->next = tmp;
        p = tmp;
        p->val = sum / 10;
      }
      if (pl1 != NULL) {
        pl1 = pl1->next;
      }
      if (pl2 != NULL) {
        pl2 = pl2->next;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n1, n2;
  ListNode *l1 = new ListNode, *l2 = new ListNode;
  ListNode *p1 = l1, *p2 = l2;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    cin >> p1->val;
    if (i != n1 - 1) {
      ListNode *tmp = new ListNode;
      p1->next = tmp;
      p1 = p1->next;
    }
  }
  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> p2->val;
    if (i != n2 - 1) {
      ListNode *tmp = new ListNode;
      p2->next = tmp;
      p2 = p2->next;
    }
  }

  Solution *s = new (Solution);
  ListNode *res = s->addTwoNumbers(l1, l2);
  while (res != NULL) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}
