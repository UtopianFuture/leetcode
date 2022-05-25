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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode *, int> m;
    ListNode *p = headA;
    while (p) {
      m[p] = 1;
      p = p->next;
    }
    ListNode *q = headB;
    while (q) {
      if (m[q] == 1) {
        break;
        ;
      }
      q = q->next;
    }
    return q;
  }
};

int main(int argc, char *argv[]) { return 0; }
