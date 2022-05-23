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
  ListNode *reverseList(ListNode *head) {
    ListNode *prev, *pos, *next;
    prev = head;
    if (!prev) {
      return NULL;
    }
    pos = head->next;
    if (!pos) {
      return prev;
    }
    next = pos->next;
    prev->next = NULL;
    if (!next) {
      pos->next = prev;
    }
    while (pos) {
      pos->next = prev;
      prev = pos;
      pos = next;
      if (next)
        next = next->next;
    }
    return prev;
  }
};

int main(int argc, char *argv[]) { return 0; }
