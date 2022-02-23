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
    if (one == NULL) {
      return false;
    }
    if (two->next == NULL) {
      return false;
    } else {
      two = two->next;
      if (two == NULL) {
        return false;
      } else {
        two = two->next;
      }
    }

    while (one != NULL && two != NULL) {
      if (one == two) {
        return true;
      } else {
        one = one->next;
        two = two->next;
        if (two == NULL) {
          return false;
        } else {
          two = two->next;
        }
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }
