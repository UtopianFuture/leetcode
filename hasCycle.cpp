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
  bool hasCycle(ListNode *head) {
    ListNode *one = head;
    ListNode *two = head;
    while (two != NULL) {
      one = one->next;
      two = two->next;
      if (two == NULL) {
        return false;
      } else {
        two = two->next;
      }
      if (one == two) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }
