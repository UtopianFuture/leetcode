#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

struct Node {
  int lenght;
  int left, right;
  int isUsed;
  int index;
  struct Node *next, *prev;
  Node(){};
  Node(int lenght, int left, int right, int isUsed, int index,
       struct Node *next, struct Node *prev) {
    this->lenght = lenght;
    this->left = left;
    this->right = right;
    this->isUsed = isUsed;
    this->index = index;
    this->next = next;
    this->prev = prev;
  };
};

class ExamRoom1 {
private:
  struct Node *head, *tail;
  int n;

public:
  ExamRoom1(int n) {
    struct Node *head = new Node;
    struct Node *tail = new Node;
    struct Node *p = new Node(n, 0, n, false, -1, tail, head);
    head->next = p;
    tail->prev = p;
    this->n = n;
    this->head = head;
    this->tail = tail;
  }

  int seat() {
    if (!head->next->isUsed && head->next->lenght == n) {
      struct Node *p = new Node(1, 0, 1, 1, 0, head->next, head);
      head->next = p;
      p->next->left = 1;
      p->next->lenght--;
      if (p->next->lenght != p->next->right - p->next->left) {
        return -1;
      }
      p->next->prev = p;
      return 0;
    } else {
      int maxlenght = INT_MIN;
      struct Node *p = head->next;
      struct Node *maxn;
      while (p != tail) {
        if (!p->isUsed) {
          if (p->lenght > maxlenght) {
            maxlenght = p->lenght;
            maxn = p;
          }
        }

        p = p->next;
      }
      int index = (maxn->left + maxn->right) / 2;
      struct Node *rightHalf =
          new Node(maxn->right - index, index + 1, maxn->right, false, -1,
                   maxn->next, NULL);
      if (rightHalf->next->lenght !=
          rightHalf->next->right - rightHalf->next->left) {
        return -1;
      }
      struct Node *used =
          new Node(1, index, index + 1, true, index, rightHalf, maxn);
      rightHalf->prev = used;
      maxn->right = index;
      maxn->lenght = index - maxn->left;
      maxn->next = used;

      if (maxn->next->lenght != maxn->next->right - maxn->next->left) {
        return -1;
      }
      return index;
    }
  }

  void leave(int p) {
    struct Node *q = head->next;
    while (q != tail) {
      if (q->isUsed && q->index == p) {
        break;
      }
      q = q->next;
    }
    q->prev->right = q->next->right;
    q->prev->lenght = q->prev->lenght + q->next->lenght + 1;
    q->prev->next = q->next->next;
    q->next->next->prev = q->prev;
    free(q->next);
    free(q);
  }
};

class ExamRoom {
private:
  int n;
  set<int> s;

public:
  ExamRoom(int n) { this->n = n; }

  int seat() {
    if (s.empty()) {
      s.insert(0);
      return 0;
    }
    int pos = 0, pre = -1, maxDist = 0;
    for (int cur : s) {
      int dist = (cur - pre) / 2;
      if (dist > maxDist) {
        pos = pre == -1 ? 0 : pre + dist;
        maxDist = pre == -1 ? cur : dist;
      }
      pre = cur;
    }
    if (n - pre - 1 > maxDist) {
      pos = n - 1;
    }
    s.insert(pos);
    return pos;
  }

  void leave(int p) { s.erase(p); }
};

int main(int argc, char *argv[]) { return 0; }
