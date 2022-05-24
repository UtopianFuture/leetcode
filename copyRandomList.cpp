#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return NULL;
    }

    unordered_map<Node *, Node *> m;
    Node *p = head;
    while (p) {
      m[p] = new Node(p->val);
      p = p->next;
    }

    Node *q = head;
    while (q) {
      m[q]->next = m[q->next];
      m[q]->random = m[q->random];
      q = q->next;
    }
    return m[head];
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  Node *n0 = new Node(7);
  Node *n1 = new Node(13);
  n0->next = n1;
  Node *n2 = new Node(11);
  n1->next = n2;
  Node *n3 = new Node(10);
  n2->next = n3;
  Node *n4 = new Node(1);
  n3->next = n4;
  n0->random = NULL;
  n1->random = n0;
  n2->random = n4;
  n3->random = n2;
  n4->random = n0;
  Solution *s = new Solution;
  s->copyRandomList(n0);
  return 0;
}
