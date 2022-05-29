#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

class Node {
public:
  int val;
  Node *next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node *_next) {
    val = _val;
    next = _next;
  }
};

class Solution {
public:
  Node *insert(Node *head, int insertVal) {
    if (head == NULL) {
      head = new Node(insertVal);
      head->next = head;
      return head;
    }

    Node *cur = head;
    while (cur->next != head) {
      if (cur->next->val < cur->val) {
        if (cur->next->val >= insertVal)
          break;
        else if (cur->val <= insertVal)
          break;
      }
      if (cur->val <= insertVal && cur->next->val >= insertVal)
        break;
      cur = cur->next;
    }
    cur->next = new Node(insertVal, cur->next);
    return head;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  Node *head = new Node;
  Node *p = head;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    Node *tmp = new Node(val);
    p->next = tmp;
    p = p->next;
  }
  p->next = head->next;

  int insertVal;
  cin >> insertVal;

  Solution *s = new Solution;
  p = s->insert(head->next, insertVal);
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
  return 0;
}
