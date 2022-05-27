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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head->next) {
      return NULL;
    }
    ListNode *first = head, *second = head;
    ListNode *prev = head;
    while (first) {
      first = first->next;
      if (n == 0) {
        prev = second;
        second = second->next;
      }
      if (n) {
        n--;
      }
    }
    if (second == head) {
      return head->next;
    }
    prev->next = second->next;
    return head;
  }
};

int main(int argc, char *argv[]) { return 0; }
