#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *findHead(ListNode *head, ListNode *one) {
    ListNode *p = head;
    while (p != one) {
      p = p->next;
      one = one->next;
    }
    return p;
  }

  ListNode *detectCycle(ListNode *head) {
    ListNode *one = head;
    ListNode *two = head;
    while (two != NULL) {
      one = one->next;
      two = two->next;
      if (two == NULL) {
        return NULL;
      } else {
        two = two->next;
      }
      if (one == two) {
        return findHead(head, one);
      }
    }
    return NULL;
  }
};

int main(int argc, char *argv[]) { return 0; }
