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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }
    if (!head->next) {
      return head;
    }

    int pos = 1;
    ListNode *pre = head;
    ListNode *cur = head;
    ListNode *next = head->next;
    ListNode *pre_lnode, *lnode, *rnode;
    while (cur) {
      if (pos >= left && pos <= right) {
        if (pos == left) {
          pre_lnode = pre;
          lnode = cur;
        }
        if (pos == right) {
          rnode = cur;
        }
        cur->next = pre;
      }
      pos++;
      pre = cur;
      cur = next;
      if (next) {
        next = next->next;
      }
      if (pos == right + 1) {
        break;
      }
    }
    if (left != 1) {
      pre_lnode->next = rnode;
      lnode->next = cur;
      return head;
    } else {
      lnode->next = cur;
      return rnode;
    }
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n, left, right;
  cin >> n >> left >> right;

  int tmp;
  ListNode *head = new ListNode();
  ListNode *p = head;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ListNode *tmpl = new ListNode(tmp);
    p->next = tmpl;
    p = tmpl;
  }

  Solution *s = new Solution;
  ListNode *res = s->reverseBetween(head->next, left, right);
  while (res) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}
