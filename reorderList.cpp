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

class Solution1 {
public:
  void reorderList(ListNode *head) {
    vector<ListNode *> tmp;
    ListNode *p = head;
    while (p != NULL) {
      tmp.push_back(p);
      // cout << tmp.back() << endl;
      p = p->next;
    }

    int n = tmp.size();
    int left = 1, right = n - 1;
    p = head;
    assert(p == tmp[0]);
    while (left < right) {
      // cout << tmp[left] << " " << tmp[right] << endl;
      p->next = tmp[right];
      p = p->next;
      p->next = tmp[left];
      p = p->next;
      right--;
      left++;
      cout << p << " " << p->next << endl;
      cout << right << " " << left << endl;
    }
    if (left == right) {
      p->next = tmp[left];
    }
  }
};

int main(int argc, char *argv[]) { return 0; }
