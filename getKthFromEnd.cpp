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
  ListNode *getKthFromEnd(ListNode *head, int k) {
    int i = 0;
    ListNode *p = head;
    while (p) {
      i++;
      p = p->next;
    }
    p = head;
    while (i != k) {
      p = p->next;
      i--;
    }
    return p;
  }
};

int main(int argc, char *argv[]) { return 0; }
