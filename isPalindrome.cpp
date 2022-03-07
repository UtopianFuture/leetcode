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
  ListNode *reverse(ListNode *head) {
    ListNode *pre, *cur, *next;
    pre = NULL;
    cur = head;
    while (cur != NULL) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

  bool isPalindrome(ListNode *head) {
    ListNode *slow = head,
             *fast = head; // slow and fast point to find middle node
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != NULL) {
      slow = slow->next;
    }

    ListNode *left = head;
    ListNode *right = reverse(slow);
    // ListNode *tmp = right;
    while (right != NULL) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }

    // restore linklist
    // left->next = reverse(tmp);
    return true;
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
  if (s->isPalindrome(head)) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }

  return 0;
}
