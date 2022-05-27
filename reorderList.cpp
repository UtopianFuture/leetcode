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
  void reorderList(ListNode *head) {
    if (!head || !head->next) {
      return;
    }
    ListNode *one = head;
    ListNode *two = head->next;
    // find middle node
    while (two && two->next) {
      two = two->next->next;
      one = one->next;
    }

    // reverse the latter part
    ListNode *prev = NULL;
    ListNode *cur = one->next;
    ListNode *next;
    // disconnect front part and latter part
    one->next = NULL;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    // merge two list
    ListNode *first = head;
    ListNode *second = prev;
    ListNode *first_next;
    ListNode *second_next;
    while (first && second) {
      first_next = first->next;
      second_next = second->next;
      first->next = second;
      second->next = first_next;
      first = first_next;
      second = second_next;
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
