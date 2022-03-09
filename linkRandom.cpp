#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct ListNode {
  int val;
  struct ListNode *next;
};

class Solution1 {
private:
  int n;
  ListNode *head;

public:
  Solution1(ListNode *head) {
    this->n = 0;
    this->head = head;
    ListNode *p = head;
    while (p != NULL) {
      (this->n)++;
      p = p->next;
    }
  }

  int getRandom() {
    int r = rand() % n;
    ListNode *p = head;
    while (r != 0) {
      p = p->next;
      r--;
    }
    return p->val;
  }
};

class Solution2 {
private:
  int n;
  ListNode *head;

public:
  Solution2(ListNode *head) {
    this->n = 0;
    this->head = head;
    ListNode *p = head;
    while (p != NULL) {
      (this->n)++;
      p = p->next;
    }
  }

  int getRandom() {
    ListNode *p = head;
    int res;
    int count = 0;
    while (p != NULL) {
      count++;
      if (rand() % count == 0) {
        res = p->val;
      }
      p = p->next;
    }
    return res;
  }
};

// typedef struct {
//   int n;
//   ListNode *head;
// } Solution;
//
// Solution *solutionCreate(struct ListNode *head) {
//   Solution *s = new (Solution);
//   s->head = head;
//   s->n = 0;
//   ListNode *p = head;
//   while (p != NULL) {
//     (s->n)++;
//     p = p->next;
//   }
//   return s;
// }
//
// int solutionGetRandom(Solution *obj) {
//   int r = rand() % (obj->n);
//   ListNode *p = obj->head;
//   while (r != 0) {
//     p = p->next;
//     r--;
//   }
//   return p->val;
// }
//
// void solutionFree(Solution *obj) {
//   free(obj->head);
// }

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  ListNode *head = new (ListNode);
  ListNode *p = head;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cin >> head->val;
    } else {
      ListNode *tmp = new (ListNode);
      cin >> tmp->val;
      p->next = tmp;
      p = p->next;
    }
  }
  p->next = NULL;

  //   Solution *obj = solutionCreate(head);
  //   int param_1 = solutionGetRandom(obj);
  //   cout << param_1 << " ";
  //   param_1 = solutionGetRandom(obj);
  //   cout << param_1 << " ";
  //   param_1 = solutionGetRandom(obj);
  //   cout << param_1 << " ";
  //   param_1 = solutionGetRandom(obj);
  //   cout << param_1 << " ";
  //   param_1 = solutionGetRandom(obj);
  //   cout << param_1 << " ";
  //   solutionFree(obj);

  return 0;
}
